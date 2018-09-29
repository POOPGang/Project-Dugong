// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMap.h"

#include "BaseUnit.h"
#include "BaseTile.h"
#include "UnderworldGameState.h"

#include "UObject/ConstructorHelpers.h"

#include "Engine/World.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/StaticMesh.h"

//ctors
ATileMap::ATileMap() {
	// Set this actor to call Tick() every frame.  
	//You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Default values for tile map. Overridden by editor settings (if any)
	rows = 10;
	cols = 10;
	tileSize = 100;
	tilePadding = 10;

}

//Private Functions

//Creates a tileSize x tileSize mesh for each tile in the map.
void ATileMap::CreateTile(int row, int col){
	FVector	location = PointToLocation(row, col);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;
	ABaseTile* tile = GetWorld()->SpawnActor<ABaseTile>(baseTileBP, location, rotation, spawnInfo);
	tile->Init(Point(row, col), tileSize, tilePadding, tiles.Num(), false);
	tiles.Add(tile);
}

void ATileMap::GenerateMap() {
	//Fill map with point data
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			CreateTile(i, j);
		}
	}
}

void ATileMap::SpawnUnits() {
	FVector location = PointToLocation(rows/2, cols/2);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;
	location.Z += 83;

	ABaseUnit* unit = GetWorld()->SpawnActor<ABaseUnit>(baseUnitBP, location, rotation, spawnInfo);
}



//Protected Functions
// Called when the game starts or when spawned
void ATileMap::BeginPlay(){
	Super::BeginPlay();

	gameState = Cast<AUnderworldGameState>(GetWorld()->GetGameState());
	if (gameState == nullptr) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Base Unit failed to aquire game state")));
		}
		return;
	}

	gameState->SetUnderworldMap(this);

	//Procedurally generate a map mesh
	if (baseTileBP) {
		GenerateMap();
	}
	else if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Failed to Spawn Tiles in Tile Map. Please supply tile blueprint in editor"));
	}

	//Place units on board.
	if (baseUnitBP) {
		SpawnUnits();
	}
	else if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Failed to Spawn Units in Tile Map. Please supply unit blueprint in editor"));
	}

}

//Public Functions
// Called every frame
void ATileMap::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

FVector ATileMap::PointToLocation(int x, int y) {
	return FVector(x * (tileSize + tilePadding), y * (tileSize + tilePadding), 0);
}
FVector ATileMap::PointToLocation(Point p) {
	return FVector(p.x * (tileSize + tilePadding), p.y * (tileSize + tilePadding), 0);
}
Point ATileMap::LocationToPoint(FVector location) {
	return Point(location.X / (tileSize + tilePadding), location.Y / (tileSize + tilePadding));
}

//Reverts tiles marked "dirty" by DisplayMovementTile
void ATileMap::ClearMovementTiles() {
	for (ABaseTile* tile : dirtyTiles) {
		tile->SwapMaterial(basicMaterial);
	}
	dirtyTiles.Empty();
}

void ATileMap::DisplayMovementTiles(ABaseUnit* unit) {
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Setting Move Tiles"));
	}

	auto moveCosts = unit->GetMoveCosts();

	if (unit->GetActionPoints() > 1) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (moveCosts[i][j] <= unit->GetMobility() && moveCosts[i][j] > 0) {
					this->operator()(i, j)->SwapMaterial(firstMoveMaterial);
					dirtyTiles.Add(this->operator()(i, j));
				}
					
				else if (moveCosts[i][j] <= unit->GetMobility() * 2 && moveCosts[i][j] > 0) {
					this->operator()(i, j)->SwapMaterial(secondMoveMaterial);
					dirtyTiles.Add(this->operator()(i, j));
				}
			}
		}
	}
	else if (unit->GetActionPoints() > 0) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (moveCosts[i][j] <= unit->GetMobility() && moveCosts[i][j] > 0){
					this->operator()(i, j)->SwapMaterial(secondMoveMaterial);
					dirtyTiles.Add(this->operator()(i, j));
				}
			}
		}
	}
	
}






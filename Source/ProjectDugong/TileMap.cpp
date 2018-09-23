// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMap.h"
#include "BaseUnit.h"
#include "BaseTile.h"
#include "MasterGameInstance.h"

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
	FVector	location = PointToLocation(row, col, tileSize, tilePadding);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;
	ABaseTile* tile = GetWorld()->SpawnActor<ABaseTile>(baseTileBP, location, rotation, spawnInfo);
	tile->Init(Point(row, col), tileSize, tilePadding, tiles.Num());
	tiles.Add(tile);
}

void ATileMap::GenerateMap() {
	//Fill map with point data
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map.Add(Point(i, j));
		}
	}

	//Generate tiles
	for (int i = 0; i < map.Num(); i++) {
		CreateTile(map[i].x, map[i].y);
	}
}

void ATileMap::SpawnUnits() {
	FVector location = PointToLocation(rows/2, cols/2, tileSize, tilePadding);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;

	location.Z += 83;

	ABaseUnit* unit = GetWorld()->SpawnActor<ABaseUnit>(baseUnitBP, location, rotation, spawnInfo);
}



//Protected Functions
// Called when the game starts or when spawned
void ATileMap::BeginPlay(){
	Super::BeginPlay();
	
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

	UMasterGameInstance* instance = Cast<UMasterGameInstance>(GetGameInstance());
	if (instance) {
		instance->SetUnderworldMap(this);
	}

}

//Public Functions
// Called every frame
void ATileMap::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void ATileMap::ClearMovementTiles() {
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Clearing Move Tiles"));
	}
	for (ABaseTile* tile : tiles) {
		tile->SwapMaterial(basicMaterial);
	}
}
void ATileMap::DisplayMovementTiles(ABaseUnit* unit) {
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Setting Move Tiles"));
	}
	for (ABaseTile* tile : tiles) {
		if (tile->InMovementRange(unit)) {
			tile->SwapMaterial(firstMoveMaterial);
		}
		else if (tile->InSprintRange(unit)) {
			tile->SwapMaterial(secondMoveMaterial);
		}
	}
}






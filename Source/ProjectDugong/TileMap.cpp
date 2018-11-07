// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMap.h"

#include "BaseUnit.h"
#include "BaseTile.h"
#include "PlayerUnit.h"
#include "EnemyUnit.h"
#include "CoverTile.h"
#include "UnderworldGameState.h"

#include "UObject/ConstructorHelpers.h"
#include "GenericPlatformMath.h"

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
	numAllies = 3;
	numEnemies = 6;

}

//Private Functions

void ATileMap::SpawnBasicTile(int row, int col){
	FVector	location = PointToLocation(row, col);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;
	ABaseTile* tile = GetWorld()->SpawnActor<ABaseTile>(baseTileBP, location, rotation, spawnInfo);
	tile->Init(Point(row, col), tileSize, tilePadding, tiles.Num());
	tiles.Add(tile);
}

void ATileMap::SpawnCoverTile(int row, int col){
	FVector	location = PointToLocation(row, col);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;
	ABaseTile* tile = GetWorld()->SpawnActor<ACoverTile>(CoverTileBP, location, rotation, spawnInfo);
	tile->Init(Point(row, col), tileSize, tilePadding, tiles.Num());
	tiles.Add(tile);
}

//Creates a tileSize x tileSize mesh for each tile in the map.
void ATileMap::SpawnTile(int row, int col){
	float choice = FGenericPlatformMath::FRand();

	if ((row <= rows / 5) || (col <= cols / 5) || row >= (rows - rows/5) || col >= (cols - cols/5)) {
		SpawnBasicTile(row, col);
	}
	else if (choice <= .8) {
		SpawnBasicTile(row, col);
	}
	else {
		SpawnCoverTile(row, col);
	}
	
}

void ATileMap::GenerateMap() {
	//Fill map with point data
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			SpawnTile(i, j);
		}
	}
}

Point ATileMap::FindPlayerSpawnLocation(){
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (operator()(i, j)->GetIsOccupied() == false) {
				return Point(i, j);
			}
		}
	}
	return Point(0, 0);
}

Point ATileMap::FindEnemySpawnLocation(){
	for (int i = rows-1; i >= 0; i--) {
		for (int j = cols-1; j >= 0; j--) {
			if (operator()(i, j)->GetIsOccupied() == false) {
				return Point(i, j);
			}
		}
	}
	return Point(rows-1, cols-1);
}

void ATileMap::SpawnPlayerTeam(){
	for (int i = 0; i < numAllies; i++) {
		Point spawnPoint = FindPlayerSpawnLocation();
		FVector spawnLocation = PointToLocation(spawnPoint);
		spawnLocation.Z += 83;
		//Spawn
		APlayerUnit* unit = GetWorld()->SpawnActor<APlayerUnit>(playerUnitBP,spawnLocation, FRotator(0,0,0));
		unit->SpawnInit(spawnPoint);
	}
}

void ATileMap::SpawnEnemyTeam(){
	for (int i = 0; i < numEnemies; i++) {
		Point spawnPoint = FindEnemySpawnLocation();
		FVector spawnLocation = PointToLocation(spawnPoint);
		spawnLocation.Z += 83;
		//Spawn
		AEnemyUnit* unit = GetWorld()->SpawnActor<AEnemyUnit>(enemyUnitBP, spawnLocation, FRotator(0, 180, 0));
		unit->SpawnInit(spawnPoint);
	}
}

void ATileMap::SpawnUnits() {
	//Redo to use SpawnInit()
	
	/*FVector location = PointToLocation(10, 10);
	FVector location2 = PointToLocation(9, 9);
	FVector enemyLocation = PointToLocation(11, 11);

	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;
	location.Z += 83;
	location2.Z += 83;
	enemyLocation.Z += 83;

	APlayerUnit* unit = GetWorld()->SpawnActor<APlayerUnit>(playerUnitBP, location, rotation, spawnInfo);
	unit->SpawnInit(Point(10,10));
	APlayerUnit* unit2 = GetWorld()->SpawnActor<APlayerUnit>(playerUnitBP, location2, rotation, spawnInfo);
	unit2->SpawnInit(Point(9, 9));
	AEnemyUnit* evilUnit = GetWorld()->SpawnActor<AEnemyUnit>(enemyUnitBP, enemyLocation, rotation, spawnInfo);
	evilUnit->SpawnInit(Point(11, 11));*/

	SpawnPlayerTeam();
	SpawnEnemyTeam();
}

bool ATileMap::ValidateEditorInput(){
	if (baseTileBP == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Red, TEXT("Failed to aquire tile blueprint. Please validate editor input"));
		return false;
	}
	
	if (CoverTileBP == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Red, TEXT("Failed to aquire cover blueprint. Please validate editor input"));
		return false;
	}

	if (baseUnitBP == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Red, TEXT("Failed to aquire base unit blueprint. Please validate editor input"));
		return false;
	}

	if (playerUnitBP == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Red, TEXT("Failed to aquire player unit blueprint. Please validate editor input"));
		return false;
	}

	if (enemyUnitBP == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Red, TEXT("Failed to aquire enemy unit blueprint. Please validate editor input"));
		return false;
	}

	if (basicMaterial == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Red, TEXT("Failed to aquire basic tile material. Please validate editor input"));
		return false;
	}

	if (firstMoveMaterial == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Red, TEXT("Failed to aquire first move display material. Please validate editor input"));
		return false;
	}

	if (secondMoveMaterial == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Red, TEXT("Failed to aquire second move display material. Please validate editor input"));
		return false;
	}
	return true;
}



bool ATileMap::AquireGameState(){
	gameState = Cast<AUnderworldGameState>(GetWorld()->GetGameState());
	if (gameState == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Tile Map failed to aquire game state")));
		return false;
	}

	return true;
}

//Protected Functions
// Called when the game starts or when spawned
void ATileMap::BeginPlay(){
	Super::BeginPlay();

	if (ValidateEditorInput() == false || AquireGameState() == false) {
		return;
	}
	
	gameState->SetUnderworldMap(this);

	//Spawn map
	GenerateMap();

	//Place units on board.
	SpawnUnits();
}

//Public Functions
// Called every frame
void ATileMap::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

FVector ATileMap::PointToLocation(int x, int y) {
	return PointToLocation(Point(x,y));
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

void ATileMap::DisplayFullRange(TArray<TArray<float>> &moveCosts, ABaseUnit * unit){
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (moveCosts[i][j] <= unit->GetMobility()) {
				this->operator()(i, j)->SwapMaterial(firstMoveMaterial);
				dirtyTiles.Add(this->operator()(i, j));
			}

			else if (moveCosts[i][j] <= unit->GetMobility() * 2 ) {
				this->operator()(i, j)->SwapMaterial(secondMoveMaterial);
				dirtyTiles.Add(this->operator()(i, j));
			}
		}
	}
}

void ATileMap::DisplayHalfRange(TArray<TArray<float>> &moveCosts, ABaseUnit * unit) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (moveCosts[i][j] <= unit->GetMobility() ) {
				this->operator()(i, j)->SwapMaterial(secondMoveMaterial);
				dirtyTiles.Add(this->operator()(i, j));
			}
		}
	}
}

void ATileMap::DisplayMovementTiles(ABaseUnit* unit) {

	auto moveCosts = unit->GetMoveCosts();

	if (unit->GetActionPoints() > 1) {
		DisplayFullRange(moveCosts, unit);
	}
	else if (unit->GetActionPoints() > 0) {
		DisplayHalfRange(moveCosts, unit);
	}
	
}

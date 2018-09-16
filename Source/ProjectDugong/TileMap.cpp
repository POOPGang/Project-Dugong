// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMap.h"
#include "Tile.h"
#include "UObject/ConstructorHelpers.h"

#include "Engine/World.h"


//ctors
ATileMap::ATileMap() {
	// Set this actor to call Tick() every frame.  
	//You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	rows = 10;
	cols = 10;
	tileSize = 100;
	tilePadding = 10;
}

//Private Functions
void ATileMap::GenerateMap() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			FVector	location(i * (tileSize + (tilePadding / 2)), j * (tileSize + (tilePadding / 2)), 0);
			FRotator rotation(0, 0, 0);
			FActorSpawnParameters spawnInfo;
			ATile* tile = GetWorld()->SpawnActor<ATile>(tileBP, location, rotation, spawnInfo);
			
			map.Add(tile);
		}
	}
}

void ATileMap::SpawnUnits() {
	ATile* tile = map[0];
	
	//Place unit at tile location + 83 in the Z direction (83 is unit height).
	FVector location = tile->GetActorLocation();
	location.Z += 83;
	
	FRotator rotation = tile->GetActorRotation();
	FActorSpawnParameters spawnInfo;
	
	map[0]->actorOnTile = GetWorld()->SpawnActor<ABaseUnit>(unitBP, location, rotation, spawnInfo);
}



//Protected Functions
// Called when the game starts or when spawned
void ATileMap::BeginPlay(){
	Super::BeginPlay();
	if (tileBP) 
		GenerateMap();
	else {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Failed to generate Tile Map. Please supply tile blueprint in editor"));
		}
	}
	
	if (unitBP) {
		SpawnUnits();
	}
	else {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Failed to Spawn Units in Tile Map. Please supply unit blueprint in editor"));
		}
	}
}

//Public Functions
// Called every frame
void ATileMap::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void ATileMap::SpawnTile(int x, int y, int z) {
	FVector	location(x, y, z);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;

	GetWorld()->SpawnActor<ATile>(location, rotation, spawnInfo);
}






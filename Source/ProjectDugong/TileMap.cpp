// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMap.h"
#include "Tile.h"

#include "Engine/World.h"


//ctors
// Sets default values
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
			ATile* tile = GetWorld()->SpawnActor<ATile>(location, rotation, spawnInfo);
			//ATile* tile = NewObject<ATile>();
			//tile->SetActorLocation(location);
			//tile->SetActorRotation(rotation);
			map.Add(tile);
		}
	}
}

void ATileMap::SpawnMap() {
	for (ATile* tile : map) {
		//GetWorld()->SpawnActor<ATile>(tile->GetActorLocation, tile->GetActorRotation);
	}
}



//Protected Functions
// Called when the game starts or when spawned
void ATileMap::BeginPlay(){
	Super::BeginPlay();

	GenerateMap();
	SpawnMap();
	
	
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






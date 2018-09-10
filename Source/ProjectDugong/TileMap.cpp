// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMap.h"
#include "Tile.h"

#include "Engine/World.h"

//Private Functions
////////////////////////////////////////////


//ctors
////////////////////////////////////////////

// Sets default values
ATileMap::ATileMap(){
 	// Set this actor to call Tick() every frame.  
	//You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	rows = 10;
	cols = 10;
}

//Public functions
////////////////////////////////////////////

// Called when the game starts or when spawned
void ATileMap::BeginPlay(){
	Super::BeginPlay();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			SpawnTile(i * 110, j * 110, 0);
		}
	}
	
}

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


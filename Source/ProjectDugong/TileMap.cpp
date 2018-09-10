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
}

//Public functions
////////////////////////////////////////////

// Called when the game starts or when spawned
void ATileMap::BeginPlay(){
	Super::BeginPlay();
	SpawnATile();
}

// Called every frame
void ATileMap::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}
void ATileMap::SpawnATile() {
	FRotator rotation(0, 0, 0);
	FVector	location(0, 0, 0);
	FActorSpawnParameters spawnInfo;
	
	GetWorld()->SpawnActor<ATile>(location, rotation, spawnInfo);
}


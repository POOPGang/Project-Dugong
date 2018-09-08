// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMap.h"


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
	
}

// Called every frame
void ATileMap::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}


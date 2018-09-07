// Fill out your copyright notice in the Description page of Project Settings.
//https://answers.unrealengine.com/questions/4259/questionspawning-blueprint-static-mesh-tiles-from.html

#include "UnderworldGenerator.h"
#include "Engine/World.h"
#include "MapTile.h"

AUnderworldGenerator::AUnderworldGenerator() {
	mapRows = 10;
	mapCols = 10;
}

void AUnderworldGenerator::BeginPlay() {
	Super::BeginPlay();
}
void AUnderworldGenerator::SpawnTile() {
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<AMapTile>(Location, Rotation, SpawnInfo);
}


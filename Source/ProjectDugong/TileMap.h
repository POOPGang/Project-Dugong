// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tile.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileMap.generated.h"

UCLASS()
class PROJECTDUGONG_API ATileMap : public AActor
{
	GENERATED_BODY()
	

private: //Private member variables and functions
	//1D array for 2D map
	TArray<ATile*> Map;
	int rows, cols;



public:	//ctors
	// Sets default values for this actor's properties
	ATileMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnATile();

	
};

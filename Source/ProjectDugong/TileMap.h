// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Types.h"
#include "BaseUnit.h"
#include "BaseTile.h"

#include "ProceduralMeshComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileMap.generated.h"

UCLASS()
class PROJECTDUGONG_API ATileMap : public AActor{
	GENERATED_BODY()
	
private: //Private member variables and functions

	//2D Map of integers to represent tiles. Each tile "location" is the bottom left corner of the square
	TArray<Point> map;

	//The procedurally generated map mesh.
	TArray<ABaseTile*> tiles;
	
	void CreateTile(int row, int col);
	void GenerateMap();
	void SpawnUnits();


public:	//ctors
	// Sets default values for this actor's properties
	ATileMap();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, Category = Actors)
	TSubclassOf<ABaseUnit> baseUnitBP;
	
	UPROPERTY(EditAnywhere, Category = Actors)
	TSubclassOf<ABaseTile> baseTileBP;

	UPROPERTY(EditAnywhere)
	int rows;

	UPROPERTY(EditAnywhere)
	int cols;

	UPROPERTY(EditAnywhere)
	int tileSize; 
	
	UPROPERTY(EditAnywhere)
	int tilePadding;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector PointToLocation(int x, int y);
	FVector PointToLocation(Point p);
	Point LocationToPoint(FVector location);
};

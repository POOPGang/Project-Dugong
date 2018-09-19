// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseUnit.h"
#include "Tile.h"

#include "ProceduralMeshComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileMap.generated.h"

UCLASS()
class PROJECTDUGONG_API ATileMap : public AActor{
	GENERATED_BODY()
	

private: //Private member variables and functions
	//Simple struct for map points
	typedef struct Point {
		int x;
		int y;

		Point(int i, int j) : x(i), y(j) {}

	} Point;

	//The procedurally generated map mesh.
	UProceduralMeshComponent* mapMesh;
	
	
	//2D Map of integers to represent tiles. Each tile "location" is the bottom left corner of the square
	//2D Map of integers to represent tiles. Each tile "location" is the bottom left corner of the square
	TArray<Point> map;
	
	void CreateTile(int row, int col, int meshSectionIndex);
	void SetTileMaterial(int meshSectionIndex);
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
	TSubclassOf<ABaseUnit> unitBP;
	
	UPROPERTY(EditAnywhere, Category = Materials)
	UMaterial* tileMaterial;

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

};

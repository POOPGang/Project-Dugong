// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Types.h"
class AUnderworldGameState;
class ABaseUnit;
class ABaseTile;


#include "ProceduralMeshComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileMap.generated.h"

UCLASS()
class PROJECTDUGONG_API ATileMap : public AActor{
	GENERATED_BODY()
	
private: //Private member variables and functions
	
	//The procedurally generated map mesh.
	TArray<ABaseTile*> tiles;
	
	//Tiles that need to be cleaned up when move display appears
	TArray<ABaseTile*> dirtyTiles;

	void CreateTile(int row, int col);
	void GenerateMap();
	void SpawnUnits();


public:	//ctors
	// Sets default values for this actor's properties
	ATileMap();

	//Operator overload to access elements of 1D array with 2D indicies
	ABaseTile* operator() (int row, int col) {
		//Check bounds
		if (row < 0 || row >= rows || col < 0 || col >= cols) {
			return nullptr;
		}

		return tiles[(row * cols) + col];
	}

protected:
	AUnderworldGameState* gameState;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, Category = Actors)
	TSubclassOf<ABaseUnit> baseUnitBP;
	
	UPROPERTY(EditAnywhere, Category = Actors)
	TSubclassOf<ABaseTile> baseTileBP;

	UPROPERTY(EditAnywhere, Category = Materials)
	UMaterial* basicMaterial;

	UPROPERTY(EditAnywhere, Category = Materials)
	UMaterial* firstMoveMaterial;
	
	UPROPERTY(EditAnywhere, Category = Materials)
	UMaterial* secondMoveMaterial;

	UPROPERTY(EditAnywhere, Category = Settings)
	int rows;

	UPROPERTY(EditAnywhere, Category = Settings)
	int cols;

	UPROPERTY(EditAnywhere, Category = Settings)
	int tileSize; 
	
	UPROPERTY(EditAnywhere, Category = Settings)
	int tilePadding;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector PointToLocation(int x, int y); 
	FVector PointToLocation(Point p); 
	Point LocationToPoint(FVector location); 

	void ClearMovementTiles();

	UFUNCTION(BlueprintCallable)
	void DisplayMovementTiles(ABaseUnit* unit);

	void SnapUnitToTile(ABaseUnit* unit, ABaseTile* tile);

};

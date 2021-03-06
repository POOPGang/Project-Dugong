// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Types.h"
class AUnderworldGameState;
class ABaseUnit;
class APlayerUnit;
class AEnemyUnit;
class ABaseTile;
class ACoverTile;



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

	void SpawnBasicTile(int row, int col);
	void SpawnCoverTile(int row, int col);
	void SpawnTile(int row, int col);

	void GenerateMap();

	Point FindPlayerSpawnLocation();
	Point FindEnemySpawnLocation();

	void SpawnPlayerTeam();
	void SpawnEnemyTeam();
	void SpawnUnits();

	bool ValidateEditorInput();
	bool AquireGameState();

	void DisplayFullRange(TArray<TArray<float>> &moveCosts, ABaseUnit * unit);
	void DisplayHalfRange(TArray<TArray<float>> &moveCosts, ABaseUnit * unit);

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
	ABaseTile* operator() (Point p) {
		return this->operator() (p.x, p.y);
	}

protected:
	AUnderworldGameState* gameState;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, Category = Actors)
	TSubclassOf<ABaseUnit> baseUnitBP;
	
	UPROPERTY(EditAnywhere, Category = Actors)
	TSubclassOf<APlayerUnit> playerUnitBP;

	UPROPERTY(EditAnywhere, Category = Actors)
	TSubclassOf<AEnemyUnit> enemyUnitBP;
	
	UPROPERTY(EditAnywhere, Category = Actors)
	TSubclassOf<ABaseTile> baseTileBP;

	UPROPERTY(EditAnywhere, Category = Actors)
	TSubclassOf<ACoverTile> CoverTileBP;

	UPROPERTY(EditAnywhere, Category = Materials)
	UMaterial* basicMaterial;

	UPROPERTY(EditAnywhere, Category = Materials)
	UMaterial* firstMoveMaterial;
	
	UPROPERTY(EditAnywhere, Category = Materials)
	UMaterial* secondMoveMaterial;

	UPROPERTY(EditAnywhere, Category = LevelGen)
	int rows;

	UPROPERTY(EditAnywhere, Category = LevelGen)
	int cols;

	UPROPERTY(EditAnywhere, Category = LevelGen)
	int tileSize; 
	
	UPROPERTY(EditAnywhere, Category = LevelGen)
	int tilePadding;

	UPROPERTY(EditAnywhere, Category = Settings)
	int numAllies;

	UPROPERTY(EditAnywhere, Category = Settings)
	int numEnemies;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector PointToLocation(int x, int y); 
	FVector PointToLocation(Point p); 
	Point LocationToPoint(FVector location); 

	void ClearMovementTiles();



	UFUNCTION(BlueprintCallable)
	void DisplayMovementTiles(ABaseUnit* unit);



	

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class ATileMap;
class ABaseUnit;
class APlayerUnit;
class AEnemyUnit;
class ABaseTile;

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "UnderworldGameState.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDUGONG_API AUnderworldGameState : public AGameState
{
	GENERATED_BODY()
	
	
private:
	ATileMap* underworldMap;
	ABaseUnit* activeUnit;
	ABaseTile* activeTile;

	int ActiveUnitIndex;
	TArray<ABaseUnit*> PlayerTeam;
	TArray<ABaseUnit*> EnemyTeam;
	
	bool isPlayerTurn;

protected:
	virtual void BeginPlay() override;

public:
	ATileMap* GetUnderworldMap();
	void SetUnderworldMap(ATileMap* map);

	UFUNCTION(BlueprintCallable)
	ABaseUnit* GetActiveUnit();

	UFUNCTION(BlueprintCallable)
	void SetActiveUnit(ABaseUnit* unit);

	UFUNCTION(BlueprintCallable)
	void ClearActiveUnit();
	
	UFUNCTION(BlueprintCallable)
	ABaseTile* GetActiveTile();

	UFUNCTION(BlueprintCallable)
	void SetActiveTile(ABaseTile* tile);

	UFUNCTION(BlueprintCallable)
	void ClearActiveTile();

	UFUNCTION(BlueprintCallable)
	void ToggleTurn();
	
	UFUNCTION(BlueprintCallable)
	bool GetIsPlayerTurn();

	UFUNCTION(BlueprintCallable)
	void CycleUnit();

	void RegisterPlayerUnit(ABaseUnit* unit);
	void UnregisterPlayerUnit(ABaseUnit* unit);

	void RegisterEnemyUnit(ABaseUnit* unit);
	void UnregisterEnemyUnit(ABaseUnit* unit);

	void BeginPlayerTurn();
	void BeginEnemyTurn();

	void UpdatePlayerTurn();
	void UpdateEnemyTurn();

	UFUNCTION(BlueprintCallable)
	void Update();
};

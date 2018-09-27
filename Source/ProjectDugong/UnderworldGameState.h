// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class ATileMap;
class ABaseUnit;
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
	void ToggleTurn();
	
	UFUNCTION(BlueprintCallable)
	bool GetIsPlayerTurn();
};

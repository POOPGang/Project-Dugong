// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ATileMap;
class ABaseUnit;
class ABaseTile;

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MasterGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDUGONG_API UMasterGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
private:
	ATileMap* underworldMap;
	ABaseUnit* activeUnit;
	ABaseTile* activeTile;

public:
	ATileMap* GetUnderworldMap();
	void SetUnderworldMap(ATileMap* map);

	UFUNCTION(BlueprintCallable)
	ABaseUnit* GetActiveUnit();

	UFUNCTION(BlueprintCallable)
	void SetActiveUnit(ABaseUnit* unit);
	
};

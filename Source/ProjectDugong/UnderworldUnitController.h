// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ABaseUnit;
class ABaseTile;

#include "CoreMinimal.h"
#include "AIController.h"
#include "UnderworldUnitController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDUGONG_API AUnderworldUnitController : public AAIController
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	void MoveUnit(ABaseUnit* unit, ABaseTile* tile);

};

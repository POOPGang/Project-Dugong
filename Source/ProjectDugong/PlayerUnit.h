// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseUnit.h"
#include "PlayerUnit.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDUGONG_API APlayerUnit : public ABaseUnit
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void UnitOnClicked(AActor* TouchedActor, FKey ButtonPressed);
};
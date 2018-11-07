// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseUnit.h"
#include "EnemyUnit.generated.h"

UCLASS()
class PROJECTDUGONG_API AEnemyUnit : public ABaseUnit
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;
	void Die() override;

public:
	UFUNCTION(BlueprintCallable)
	void UnitOnClicked() override;
};

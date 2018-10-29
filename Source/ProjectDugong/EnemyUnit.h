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
	void Die();
public:
	void UnitOnClicked(AActor* TouchedActor, FKey ButtonPressed);
	void Init(FString name, int maxHP, int hp, int mobility, int aim, int maxAP, int ap, bool isMoving);
	
	void Select() override {}
	void Deselect() override {}
};

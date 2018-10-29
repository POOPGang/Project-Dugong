// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class UBillboardComponent;

#include "CoreMinimal.h"
#include "BaseUnit.h"
#include "PlayerUnit.generated.h"

UCLASS()
class PROJECTDUGONG_API APlayerUnit : public ABaseUnit
{
	GENERATED_BODY()
private:
	//UBillboardComponent* SelectionArrow;
protected:
	void BeginPlay();
	void Die();

public:

	APlayerUnit();

	UFUNCTION(BlueprintCallable)
	void UnitOnClicked();
	void Init(FString name, int maxHP, int hp, int mobility, int aim, int maxAP, int ap, bool isMoving);

	UFUNCTION(BlueprintCallable)
	void Select() override;

	void Deselect() override;
};

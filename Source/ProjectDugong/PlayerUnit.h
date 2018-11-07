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
	void BeginPlay() override;
	void Die() override;

public:

	APlayerUnit();

	UFUNCTION(BlueprintCallable)
	void UnitOnClicked() override;
	
};

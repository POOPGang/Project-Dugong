// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ATileMap;
class ABaseUnit;
class ABaseTile;

#include "GameFramework/Actor.h"
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

public:
	UPROPERTY(EditAnywhere)
	int mysterium = 0;
	
	UPROPERTY(EditAnywhere)
	FVector newPlayerLocation;
	
	UPROPERTY(EditAnywhere)
	float DOOOM = 50.0;
	
	UPROPERTY(EditAnywhere)
	AActor* newNodeSelected;
	
};

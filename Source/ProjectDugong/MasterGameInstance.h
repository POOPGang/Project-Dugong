// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ATileMap;
class ABaseUnit;
class ABaseTile;

#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MasterOverworldSave.h"
#include "Kismet/GameplayStatics.h"
#include "MasterGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDUGONG_API UMasterGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int mysterium = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int energy = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int scrap = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int explosives = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int medkits = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int rations = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector newPlayerLocation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DOOOM = .5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* newNodeSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ERROR_message = FString(TEXT("ERROR"));

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//UMasterOverworldSave* SaveGameInstance = Cast<UMasterOverworldSave>(UGameplayStatics::CreateSaveGameObject(UMasterOverworldSave::StaticClass()));

	//UFUNCTION(BlueprintCallable)
	//function to pull squad list from ?

	//UFUNCTION(BlueprintCallable)
	//function to push squad list into underworld

	//way to continually modify and update squad list within prebattle screen
	
};

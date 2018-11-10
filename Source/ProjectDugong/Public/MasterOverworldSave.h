// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MasterOverworldSave.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDUGONG_API UdistNodes : public UObject {
	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* nodeType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform nodeLocation;
};


UCLASS()
class PROJECTDUGONG_API UMasterOverworldSave : public USaveGame
{
	GENERATED_BODY()
	
	public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString SaveSlotName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int UserIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UdistNodes *> distNodes;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//TArray<UdistNodes *> dist2Nodes;

	UMasterOverworldSave();
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "UnderworldGenerator.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDUGONG_API AUnderworldGenerator : public ALevelScriptActor
{
	GENERATED_BODY()
	
public: //ctors
	AUnderworldGenerator();

protected: 
	int mapRows, mapCols;
	TArray<TArray<int>> map;
	virtual void BeginPlay() override;
	
public:

	UFUNCTION(BlueprintCallable, Category = "WorldGen")
	void SpawnTile();
	
};

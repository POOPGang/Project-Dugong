// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTile.h"
#include "CoverTile.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDUGONG_API ACoverTile : public ABaseTile
{
	GENERATED_BODY()
	
public:
	int DefenseBonus;
	ACoverTile();

};

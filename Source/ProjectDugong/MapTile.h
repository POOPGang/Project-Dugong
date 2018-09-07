// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapTile.generated.h"

UCLASS()
class PROJECTDUGONG_API AMapTile : public AActor
{
	GENERATED_BODY()
	
public: //ctors	
	// Sets default values for this actor's properties
	AMapTile();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* tileMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};

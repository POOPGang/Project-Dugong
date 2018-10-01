// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class AUnderworldGameState;
class ABaseUnit;

#include "Types.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTile.generated.h"

UCLASS()
class PROJECTDUGONG_API ABaseTile : public AActor
{
	GENERATED_BODY()
	
public:	


	// Sets default values for this actor's properties
	ABaseTile();
	void Init(Point p, int tileSize, int tilePadding, int index, bool isOccupied);

protected:
	AUnderworldGameState* gameState;
	Point gridLocation;
	
	int tileSize;
	int tilePadding;
	int index;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* tileMeshComponent;
	
	bool isOccupied;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void TileOnClicked(AActor* TouchedActor, FKey ButtonPressed);

	UFUNCTION()
	void CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent);
	
	void SwapMaterial(UMaterial* newMaterial);

	Point GetGridLocation();

};

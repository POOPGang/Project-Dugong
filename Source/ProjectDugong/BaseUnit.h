// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class AUnderworldGameState;
class ATileMap;

#include "Types.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseUnit.generated.h"

UCLASS()
class PROJECTDUGONG_API ABaseUnit : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseUnit();
	virtual void OnConstruction(const FTransform& Transform) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


protected:
	AUnderworldGameState* gameState;
	Point gridLocation;

	UPROPERTY(VisibleAnywhere)
	FString name;
	UPROPERTY(VisibleAnywhere)
	int hp;
	UPROPERTY(VisibleAnywhere)
	int mobility;
	UPROPERTY(VisibleAnywhere)
	int aim;
	UPROPERTY(VisibleAnywhere)
	int ap;

	TArray<TArray<float>> moveCosts;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void UnitOnClicked(AActor* TouchedActor, FKey ButtonPressed);

	void PopulateMoveCosts(ATileMap* map);
	TArray<TArray<float>> GetMoveCosts();
	int GetMobility();

};

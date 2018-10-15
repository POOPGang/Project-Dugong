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
	void UseActionPoint();
	ABaseTile* GetCurrentTile();

protected:
	AUnderworldGameState* gameState;
	Point gridLocation;

	UPROPERTY(VisibleAnywhere)
	FString name;
	UPROPERTY(VisibleAnywhere)
	int maxHP;
	UPROPERTY(VisibleAnywhere)
	int hp;
	UPROPERTY(VisibleAnywhere)
	int mobility;
	UPROPERTY(VisibleAnywhere)
	int aim;
	UPROPERTY(VisibleAnywhere)
	int maxAP;
	UPROPERTY(VisibleAnywhere)
	int ap;
	UPROPERTY(VisibleAnywhere)
	bool isMoving;

	TArray<TArray<float>> moveCosts;


public:	
	void SpawnInit(Point p);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	void UnitOnClicked(AActor* TouchedActor, FKey ButtonPressed);
	
	void PopulateMoveCosts(ATileMap* map);
	
	TArray<TArray<float>> GetMoveCosts();
	
	int GetMobility();

	UFUNCTION(BlueprintCallable)
	int GetActionPoints();

	UFUNCTION(BlueprintCallable) 
	bool GetIsMoving();

	UFUNCTION()
	void RefreshActionPoints();

	

	UFUNCTION(BlueprintCallable)
	bool StartMoving(ABaseTile* target);

	void Run();

	void Walk();
	
	UFUNCTION(BlueprintCallable)
	void StopMoving(ABaseTile* target);
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyUnit.h"
#include "UnderworldGameState.h"

void AEnemyUnit::BeginPlay() {
	Super::BeginPlay();

	gameState->RegisterPlayerUnit(this);
}

void AEnemyUnit::Die() {
	gameState->UnregisterEnemyUnit(this);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Oh, the pain")));
	Destroy();
}

void AEnemyUnit::UnitOnClicked() {
	//	Returns when clicked on and states it is an enemy unit.
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("An Enemy unit.")));
	return;

}


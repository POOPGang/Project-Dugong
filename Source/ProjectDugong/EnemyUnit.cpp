// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyUnit.h"
#include "UnderworldGameState.h"

void AEnemyUnit::BeginPlay() {
	Super::BeginPlay();

	gameState->RegisterEnemyUnit(this);
}

void AEnemyUnit::Die() {
	gameState->UnregisterEnemyUnit(this);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Oh, the pain")));
	Destroy();
}

void AEnemyUnit::UnitOnClicked() {
	Super::UnitOnClicked();

}


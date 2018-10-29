// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyUnit.h"
#include "UnderworldGameState.h"

void AEnemyUnit::Die() {
	gameState->UnregisterEnemyUnit(this);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Oh, the pain")));

}

void AEnemyUnit::UnitOnClicked(AActor* TouchedActor, FKey ButtonPressed) {
	//	Returns when clicked on and states it is an enemy unit.
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("An Enemy unit.")));
	return;

}

//	Initialization function to set instances of AEnemyUnit to desired settings (To be Determined)
void AEnemyUnit::Init(FString name, int maxHP, int hp, int mobility, int aim, int maxAP, int ap, bool isMoving) {
	this->name = name;
	this->maxHP = maxHP;
	this->hp = hp;
	this->mobility = mobility;
	this->aim = aim;
	this->maxAP = maxAP;
	this->ap = ap;
	this->isMoving = isMoving;
}


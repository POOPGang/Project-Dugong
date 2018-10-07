// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerUnit.h"

void APlayerUnit::UnitOnClicked(AActor* TouchedActor, FKey ButtonPressed) {
	//Call to the parent't implementation of UnitOnClicked
	ABaseUnit::UnitOnClicked(TouchedActor, ButtonPressed);

	//Extended behavior
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("My name is: %s"), *name));
}

//	Initialization function to set instances of APlayerUnit to desired settings
void APlayerUnit::Init(FString name, int maxHP, int hp, int mobility, int aim, int maxAP, int ap, bool isMoving) {
	this->name = name;
	this->maxHP = maxHP;
	this->hp = hp;
	this->mobility = mobility;
	this->aim = aim;
	this->maxAP = maxAP;
	this->ap = ap;
	this->isMoving = isMoving;
}
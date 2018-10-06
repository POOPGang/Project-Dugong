// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerUnit.h"

/**/

void APlayerUnit::UnitOnClicked(AActor* TouchedActor, FKey ButtonPressed) {
	//Call to the parent't implementation of UnitOnClicked
	ABaseUnit::UnitOnClicked(TouchedActor, ButtonPressed);

	//Extended behavior
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("My name is: %s"), *name));
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerUnit.h"

#include "Engine/Classes/Components/BillboardComponent.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"

#include "ConstructorHelpers.h"
#include "UnderworldGameState.h"

void APlayerUnit::BeginPlay() {
	Super::BeginPlay();

	gameState->RegisterPlayerUnit(this);

}

void APlayerUnit::Die(){
	Super::Die();

	gameState->UnregisterPlayerUnit(this);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Oh, the pain")));

}

APlayerUnit::APlayerUnit(){
	/*SelectionArrow = CreateDefaultSubobject<UBillboardComponent>(TEXT("Selection Arrow"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> SelectionArrowAsset(TEXT("/Game/Textures/SelectionArrow.SelectionArrow"));
	SelectionArrow->SetupAttachment(RootComponent);
	SelectionArrow->Sprite =  SelectionArrowAsset.Object;
	SelectionArrow->SetVisibility(false);
	SelectionArrow->SetHiddenInGame(false);*/

}

void APlayerUnit::UnitOnClicked() {
	//Call to the parent't implementation of UnitOnClicked
	Super::UnitOnClicked();

	//Extended behavior
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("My name is: %s"), *name));
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

void APlayerUnit::Select(){
	//SelectionArrow->SetVisibility(true);
}

void APlayerUnit::Deselect(){
	//SelectionArrow->SetVisibility(false);
}

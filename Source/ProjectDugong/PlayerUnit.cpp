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
	Destroy();
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
}

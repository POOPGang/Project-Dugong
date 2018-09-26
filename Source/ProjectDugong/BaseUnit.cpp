// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseUnit.h"
#include "UnderworldGameState.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABaseUnit::ABaseUnit(){
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Set default values
	name = "A Base Unit";
	hp = 4;
	mobility = 5;
	aim = 65;
	ap = 2;
	
	
}
void ABaseUnit::OnConstruction(const FTransform& Transform) {
	Super::OnConstruction(Transform);

}

// Called when the game starts or when spawned
void ABaseUnit::BeginPlay(){
	Super::BeginPlay();
	
}

// Called every frame
void ABaseUnit::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseUnit::UnitOnClicked(AActor* TouchedActor, FKey ButtonPressed) {
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Unit Clicked")));
	}
	
	AUnderworldGameState* gameState = Cast<AUnderworldGameState>(GetWorld()->GetGameState());
	if (gameState) {
		gameState->SetActiveUnit(this);
	}
	else if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Failed to aquire game instance")));
	}
}
int ABaseUnit::GetMobility() {
	return mobility;
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "UnderworldPlayerPawn.h"


// Sets default values
AUnderworldPlayerPawn::AUnderworldPlayerPawn(){
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementSpeed = 1000;

}

// Called when the game starts or when spawned
void AUnderworldPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnderworldPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUnderworldPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


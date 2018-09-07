// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypeUnit.h"


// Sets default values
APrototypeUnit::APrototypeUnit()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APrototypeUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APrototypeUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APrototypeUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


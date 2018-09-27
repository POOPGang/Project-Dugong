// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseUnit.h"

#include "TileMap.h"
#include "Types.h"
#include "UnderworldGameState.h"

#include "UObject/ConstructorHelpers.h"
#include "Queue.h"

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

	gameState = Cast<AUnderworldGameState>(GetWorld()->GetGameState());
	if (gameState  == nullptr) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Base Unit failed to aquire game state")));
		}
		return;
	}

	//Init movement cost array to -1 for later pathfinding
	for (int i = 0; i < gameState->GetUnderworldMap()->rows; i++) {
		TArray<int> temp;
		temp.Init(-1, gameState->GetUnderworldMap()->cols);
		moveCosts.Add(temp);
	}

	gridLocation = gameState->GetUnderworldMap()->LocationToPoint(this->GetActorLocation());
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
	gameState->SetActiveUnit(this);
}

void ABaseUnit::PopulateMoveCosts(ATileMap* map) {
	TQueue<Point> q;
	TArray<TArray<bool>> visited;
	for (int i = 0; i < map->rows; i++) {
		TArray<bool> temp;
		temp.Init(false, map->cols);
		visited.Add(temp);
	}
	q.Enqueue(gridLocation);
	moveCosts[gridLocation.x][gridLocation.y] = 0;

}

int ABaseUnit::GetMobility() {
	return mobility;
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "UnderworldGameState.h"
#include "TileMap.h"
#include "BaseUnit.h"
#include "BaseTile.h"

void AUnderworldGameState::BeginPlay() {
	Super::BeginPlay();
	isPlayerTurn = true;
}

ATileMap* AUnderworldGameState::GetUnderworldMap() {
	return underworldMap;
}

void AUnderworldGameState::SetUnderworldMap(ATileMap* map) {
	underworldMap = map;
}

ABaseUnit* AUnderworldGameState::GetActiveUnit() {
	return activeUnit;
}

void AUnderworldGameState::SetActiveUnit(ABaseUnit* unit) {
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Setting active unit")));
	
	//Failure states. Returning here prevents segmentation faults.
	if (underworldMap == nullptr || unit == nullptr) {
		return;
	}
		
	//If the user clicks on the same unit twice, no action is necessary
	if (activeUnit == unit) {
		return;
	}

	//If there is already an active unit, clear the tile highlighting before re-applying.
	if (activeUnit != nullptr) {
		underworldMap->ClearMovementTiles();
	}
	
	activeUnit = unit;
	activeUnit->PopulateMoveCosts(underworldMap);
	underworldMap->DisplayMovementTiles(activeUnit);

}
void AUnderworldGameState::ClearActiveUnit() {
	if (activeUnit == nullptr)
		return;

	activeUnit = nullptr;
	
	if (underworldMap) {
		underworldMap->ClearMovementTiles();
	}
	else {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("No underworld map set.")));
		}
	}
}

void AUnderworldGameState::ToggleTurn() {
	isPlayerTurn = !isPlayerTurn;
}

bool AUnderworldGameState::GetIsPlayerTurn() {
	return isPlayerTurn;
}
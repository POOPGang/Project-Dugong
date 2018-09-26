// Fill out your copyright notice in the Description page of Project Settings.

#include "UnderworldGameState.h"
#include "TileMap.h"
#include "BaseUnit.h"
#include "BaseTile.h"


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
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Setting active unit")));
	}
	//If there is already an active unit, clear the tile highlighting before re-applying.
	if (activeUnit != nullptr) {
		underworldMap->ClearMovementTiles();
	}
	if (unit == nullptr) {
		underworldMap->ClearMovementTiles();
		return;
	}

	activeUnit = unit;

	if (underworldMap) {
		underworldMap->DisplayMovementTiles(activeUnit);
	}
	else {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("No underworld map set.")));
		}
	}

}
void AUnderworldGameState::ClearActiveUnit() {
	/*activeUnit = nullptr;
	
	if (underworldMap) {
		underworldMap->ClearMovementTiles();
	}
	else {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("No underworld map set.")));
		}
	}*/
}


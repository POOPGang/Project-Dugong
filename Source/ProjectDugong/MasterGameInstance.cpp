// Fill out your copyright notice in the Description page of Project Settings.

#include "MasterGameInstance.h"
#include "TileMap.h"
#include "BaseUnit.h"
#include "BaseTile.h"

ATileMap* UMasterGameInstance::GetUnderworldMap() { 
	return underworldMap;
}

void UMasterGameInstance::SetUnderworldMap(ATileMap* map) {
	underworldMap = map;
}

ABaseUnit* UMasterGameInstance::GetActiveUnit() {
	return activeUnit;
}

void UMasterGameInstance::SetActiveUnit(ABaseUnit* unit) {
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Setting active unit")));
	}
	//If there is already an active unit, clear the tile highlighting before re-applying.
	if (activeUnit != nullptr) {
		underworldMap->ClearMovementTiles(activeUnit);
	}
	
	activeUnit = unit;

	underworldMap->DisplayMovementTiles(activeUnit);

}

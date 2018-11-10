// Fill out your copyright notice in the Description page of Project Settings.

#include "UnderworldGameState.h"
#include "TileMap.h"
#include "BaseUnit.h"
#include "PlayerUnit.h"
#include "BaseTile.h"

void AUnderworldGameState::BeginPlay() {
	Super::BeginPlay();
	isPlayerTurn = true;
	ActiveUnitIndex = 0;
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

ABaseTile* AUnderworldGameState::GetActiveTile() {
	return activeTile;
}

void AUnderworldGameState::SetActiveTile(ABaseTile* tile) {
	this->activeTile = tile;
}

void AUnderworldGameState::ClearActiveTile() {
	this->activeTile = nullptr;
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
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Toggling Turn")));
	//isPlayerTurn = !isPlayerTurn;
	if (isPlayerTurn) {
		BeginEnemyTurn();
	}
	else {
		BeginPlayerTurn();
	}

	isPlayerTurn = !isPlayerTurn;

}

bool AUnderworldGameState::GetIsPlayerTurn() {
	return isPlayerTurn;
}

//Depricated. Only works for player team
void AUnderworldGameState::CycleUnit(){
	ActiveUnitIndex = (ActiveUnitIndex + 1) % PlayerTeam.Num();
	SetActiveUnit(PlayerTeam[ActiveUnitIndex]);
}

void AUnderworldGameState::RegisterPlayerUnit(ABaseUnit* unit){
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Register Player Unit.")));
	PlayerTeam.Add(unit);
}

void AUnderworldGameState::UnregisterPlayerUnit(ABaseUnit * unit){
	//TODO
}

void AUnderworldGameState::RegisterEnemyUnit(ABaseUnit* unit){
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Register Enemy Unit.")));
	EnemyTeam.Add(unit);
}

void AUnderworldGameState::UnregisterEnemyUnit(ABaseUnit * unit){
	//TODO
}

void AUnderworldGameState::BeginPlayerTurn() {
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Begin Player Turn.")));
	ActiveUnitIndex = 0;
	for (auto unit : PlayerTeam) {
		unit->RefreshActionPoints();
	}
}

void AUnderworldGameState::BeginEnemyTurn(){
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("Begin Enemy Turn.")));
	ActiveUnitIndex = 0;
	for (auto unit : EnemyTeam) {
		unit->RefreshActionPoints();
	}
}

void AUnderworldGameState::UpdatePlayerTurn(){
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("PlayerTeamSize: %d."), PlayerTeam.Num()));
	for (auto unit : PlayerTeam) {
		//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("UnitAP: %d."), unit->GetActionPoints()));
		if (unit->GetActionPoints() > 0) {
			return;
		}
	}
	ToggleTurn();
}

void AUnderworldGameState::UpdateEnemyTurn(){
	for (auto unit : EnemyTeam) {
		if (unit->GetActionPoints() > 0) {
			return;
		}
	}
	ToggleTurn();
}

void AUnderworldGameState::Update(){
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Update.")));
	if (isPlayerTurn) {
		UpdatePlayerTurn();
	}
	else {
		UpdateEnemyTurn();
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "UnderworldUnitController.h"

#include "BaseUnit.h"
#include "BaseTile.h"

void AUnderworldUnitController::MoveUnitToTile(ABaseUnit* unit, ABaseTile* target) {
	auto costMap = unit->GetMoveCosts();
	if (unit->GetMobility() >= costMap[target->GetGridLocation().x][target->GetGridLocation().y]) {
		//unit->setAction
	}
}
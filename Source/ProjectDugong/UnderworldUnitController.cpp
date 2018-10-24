// Fill out your copyright notice in the Description page of Project Settings.

#include "UnderworldUnitController.h"

#include "BaseUnit.h"
#include "BaseTile.h"

void AUnderworldUnitController::MoveUnit(ABaseUnit* unit, ABaseTile* target) {
	//Ensure Unit is elligable to move
	if (unit->GetActionPoints() <= 0) {
		return;
	}

	
	unit->SetCanAffectNavigationGeneration(false);
	unit->StartMoving(target);
	MoveToActor(target, 0.1, false, true, true, DefaultNavigationFilterClass, false);
	unit->StopMoving(target);
	unit->SetCanAffectNavigationGeneration(false);
}
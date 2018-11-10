// Fill out your copyright notice in the Description page of Project Settings.

#include "UnderworldUnitController.h"

#include "BaseUnit.h"
#include "BaseTile.h"

void AUnderworldUnitController::MoveUnit(ABaseUnit* unit, ABaseTile* target) {
	//Ensure Unit is elligable to move
	
	auto moveCosts = unit->GetMoveCosts();

	if (unit->GetActionPoints() <= 0 || moveCosts[target->GetGridLocation().x][target->GetGridLocation().y] > (unit->GetMobility() * unit->GetActionPoints())) {
		return;
	}
	
	unit->SetCanAffectNavigationGeneration(false);
	unit->StartMoving(target);
	MoveToLocation(target->GetActorLocation(), 0.5, false, true, true);
	unit->StopMoving(target);
	unit->TakeCover();
	unit->SetCanAffectNavigationGeneration(false);

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("Defense Bonus: %d"), unit->GetDefense()));
}
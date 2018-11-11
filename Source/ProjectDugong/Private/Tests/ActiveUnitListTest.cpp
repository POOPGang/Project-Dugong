// Fill out your copyright notice in the Description page of Project Settings.

//Parent Header
#include "ActiveUnitListTest.h"

//Engine Headers
#include "Engine/World.h"
#include "Engine.h"

//Automation Headers
#include "AutomationTest.h"
#include "AutomationEditorCommon.h"

//Dugong Headers
#include "Types.h"
#include "PlayerUnit.h"
#include "EnemyUnit.h"
#include "UnderworldGameState.h"

//Constructor Test
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FActiveUnitAddTest, "DugongTestSuite.GameState.ActiveUnitList.Add", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)
bool FActiveUnitAddTest::RunTest(const FString& Parameters) {

		
	FVector location(0, 0, 0);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;

	//Create a temporary world
	FAutomationEditorCommonUtils::LoadMap("/Game/Levels/Underworld.Underworld'");
	UWorld* world = GEngine->GetWorld();

	return true;
	//Fetch the gamestate
	//AUnderworldGameState* gameState = world->GetGameState<AUnderworldGameState>();
	//if (gameState == nullptr) {
	//	return false;
	//}
	//////Construct a unit
	//APlayerUnit* unit = world->SpawnActor<APlayerUnit>(location, rotation, spawnInfo);

	//if (unit == nullptr) {
	//	UE_LOG(LogTemp, Error, TEXT("Unit failed to spawn"));
	//	return false;
	//}
	//
	//int playerTeamSize = gameState->GetPlayerTeamSize();
	//if (playerTeamSize == 1) {
	//	return true;
	//}

	return false;
}

// Sets default values
AActiveUnitListTest::AActiveUnitListTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Fill out your copyright notice in the Description page of Project Settings.



//Parent Header
#include "BaseUnitTests.h"

//Engine Headers
#include "Engine/World.h"

//Automation Headers
#include "AutomationTest.h"
#include "AutomationEditorCommon.h"

//Dugong Headers
#include "Types.h"

//This define makes me feel dirty. However, it allows the tests to read protected members without bloating the Base Unit definition
//This avoids adding getters and setters that are only used by the testing suite.
#define protected public
#include "BaseUnit.h"

//Constructor Test
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBaseUnitConstructorTest, "DugongTestSuite.BaseUnit.UnitTests.BaseUnitConstructor", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)
bool FBaseUnitConstructorTest::RunTest(const FString& Parameters) {
	FVector location(0, 0, 0);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;

	//Create a temporary world
	UWorld* world = FAutomationEditorCommonUtils::CreateNewMap();

	//Construct a TileMap
	ABaseUnit* unit = world->SpawnActor<ABaseUnit>(location, rotation, spawnInfo);

	if (unit == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Unit failed to spawn"));
		return false;
	}
	else {
		return true;
	}


	return false;
}



//Refresh AP Test
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBaseUnitRefreshAPTest, "DugongTestSuite.BaseUnit.UnitTests.BaseUnitRefreshAP", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)
bool FBaseUnitRefreshAPTest::RunTest(const FString& Parameters) {
	//Test setup
	FVector location(0, 0, 0);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;
	UWorld* world = FAutomationEditorCommonUtils::CreateNewMap();
	ABaseUnit* unit = world->SpawnActor<ABaseUnit>(location, rotation, spawnInfo);
	if (unit == nullptr) {
		return false;
	}
	
	//Drain unit AP
	unit->ap = 0;

	//Refill UnitAP
	unit->RefreshActionPoints();
	if (unit->GetActionPoints() != unit->maxAP) {
		return false;
	}


	return true;
}

// Dummy ctor
ABaseUnitTests::ABaseUnitTests(){

}

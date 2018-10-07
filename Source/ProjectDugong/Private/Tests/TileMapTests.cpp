// Fill out your copyright notice in the Description page of Project Settings.

//Parent Header
#include "TileMapTests.h"

//Engine Headers
#include "Engine/World.h"

//Automation Headers
#include "AutomationTest.h"
#include "AutomationEditorCommon.h"

//Dugong Headers
#include "Types.h"
#include "TileMap.h"


//Constructor Test
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTileMapConstructorTest, "DugongTestSuite.TileMap.UnitTests.TileMapConstructor", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)
bool FTileMapConstructorTest::RunTest(const FString& Parameters){
	FVector location(0, 0, 0);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;

	//Create a temporary world
	UWorld* world = FAutomationEditorCommonUtils::CreateNewMap();

	//Construct a TileMap
	ATileMap* tileMap = world->SpawnActor<ATileMap>(location, rotation, spawnInfo);
	
	if (tileMap == nullptr) {
		UE_LOG(LogTemp, Log, TEXT("Tile map failed to spawn"));
		return false;
	}
	else {
		return true;
	}
	

	return false;
}

//Point conversion tests
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTileMapPointConversionTest, "DugongTestSuite.TileMap.UnitTests.PointConversions", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)
bool FTileMapPointConversionTest::RunTest(const FString& Parameters) {
	//Test setup
	FVector mapLocation(0, 0, 0);
	FRotator mapRotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;
	UWorld* world = FAutomationEditorCommonUtils::CreateNewMap();
	ATileMap* tileMap = world->SpawnActor<ATileMap>(mapLocation, mapRotation, spawnInfo);
	if (tileMap == nullptr) {
		return false;
	}
	

	//Map origin
	
	//For 10,000 points make a point a location then back again to make sure the conversion works.
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			Point a(0, 0);
			FVector locationA = tileMap->PointToLocation(a);
			Point b = tileMap->LocationToPoint(locationA);

			if (a != b) {
				return false;
			}

		}
	}

	return true;
}

//Dummy ctor
ATileMapTests::ATileMapTests() {}
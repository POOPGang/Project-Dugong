// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMapTests.h"

#include "TileMap.h"

#include "Engine/World.h"

#include "AutomationTest.h"
#include "AutomationEditorCommon.h"


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTileMapConstructorTest, "Test.TileMap.UnitTests.OperatorOverloads", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FTileMapConstructorTest::RunTest(const FString& Parameters){
	UE_LOG(LogTemp, Log, TEXT("Begin TileMap ctor test"));
	
	FVector location(0, 0, 0);
	FRotator rotation(0, 0, 0);
	FActorSpawnParameters spawnInfo;

	//Create a temporary world
	//UWorld* world = FAutomationEditorCommonUtils::CreateNewMap();

	//Construct a TileMap
	//ATileMap* tileMap = world->SpawnActor<ATileMap>(location, rotation, spawnInfo);

	return true;
}



//Dummy ctor
ATileMapTests::ATileMapTests() {}
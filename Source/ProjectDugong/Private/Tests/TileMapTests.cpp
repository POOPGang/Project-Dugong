// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMapTests.h"

#include "TileMap.h"
#include "AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTileMapTest, "Test.TileMapUnitTests", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FTileMapTest::RunTest(const FString& Parameters)
{
	//UE_LOG(LogTemp, Warning, TEXT("Before Hot-Reload"));

	return true;
}


//Dummy ctor
ATileMapTests::ATileMapTests() {


}
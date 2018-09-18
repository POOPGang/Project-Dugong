// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMap.h"

#include "UObject/ConstructorHelpers.h"

#include "Engine/World.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/StaticMesh.h"

//ctors
ATileMap::ATileMap() {
	// Set this actor to call Tick() every frame.  
	//You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	mapMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("MapMesh"));
	SetRootComponent(mapMesh);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map.Add(Point(i, j));
		}
	}
	
	rows = 10;
	cols = 10;
	tileSize = 100;
	tilePadding = 10;
}

//Private Functions
void ATileMap::CreateTile(int row, int col) {
	//https://www.youtube.com/watch?v=dKlMEmVgbvg
	TArray<FVector> vertices;
	TArray<int32> triangles;
	TArray<FVector> normals;
	TArray<FVector2D> UV0;
	TArray<FColor> vertexColors;
	TArray<FProcMeshTangent> tangents;

	//Add vertecies 
	FVector origin = (0 + (row * tileSize + tilePadding), 0 + (row * tileSize + tilePadding), 0);
	vertices.Add(origin);
	vertices.Add(FVector(origin.X, origin.Y + tileSize, 0));
	vertices.Add(FVector(origin.X + tileSize, origin.Y, 0));
	vertices.Add(FVector(origin.X + tileSize, origin.Y + tileSize, 0));
	

}

void ATileMap::GenerateMap() {
	//UStaticMesh *tile = tileBP->
}

void ATileMap::SpawnUnits() {
	//ATile* tile = map[0];
	//
	////Place unit at tile location + 83 in the Z direction (83 is unit height).
	//FVector location = tile->GetActorLocation();
	//location.Z += 83;
	//
	//FRotator rotation = tile->GetActorRotation();
	//FActorSpawnParameters spawnInfo;
	//
	//map[0]->actorOnTile = GetWorld()->SpawnActor<ABaseUnit>(unitBP, location, rotation, spawnInfo);
}



//Protected Functions
// Called when the game starts or when spawned
void ATileMap::BeginPlay(){
	Super::BeginPlay();
	
	//Procedurally generate a map mesh
	if (tileBP) {
		GenerateMap();
	}
	else if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Failed to Spawn Units in Tile Map. Please supply unit blueprint in editor"));
	}

	//Place units on board.
	if (unitBP) {
		SpawnUnits();
	}
	else if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Failed to Spawn Units in Tile Map. Please supply unit blueprint in editor"));
	}

}

//Public Functions
// Called every frame
void ATileMap::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}






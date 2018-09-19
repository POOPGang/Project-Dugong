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

	//Setup map mesh
	mapMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("MapMesh"));
	SetRootComponent(mapMesh);
	mapMesh->bUseAsyncCooking = true;

	//Default values for tiel map. Overridden by editor settings (if any)
	rows = 10;
	cols = 10;
	tileSize = 100;
	tilePadding = 10;
}

//Private Functions

//Creates a tileSize x tileSize mesh for each tile in the map.
void ATileMap::CreateTile(int row, int col, int meshSectionIndex){

	TArray<FVector> vertices;
	TArray<int32> indices;
	TArray<FVector> normals;
	TArray<FVector2D> UV0;
	TArray<FColor> vertexColors;
	TArray<FProcMeshTangent> tangents;

	//Add vertecies 
	FVector origin;
	origin.X = 0 + (row * (tileSize + tilePadding));
	origin.Y = 0 + (col * (tileSize + tilePadding));
	origin.Z = 0;

	vertices.Add(origin);
	vertices.Add(FVector(origin.X, origin.Y + tileSize, 0));
	vertices.Add(FVector(origin.X + tileSize, origin.Y, 0));
	vertices.Add(FVector(origin.X + tileSize, origin.Y + tileSize, 0));
	
	//Set triangle Indexes
	indices.Add(0);
	indices.Add(1);
	indices.Add(2);
	indices.Add(3);
	indices.Add(2);
	indices.Add(1);

	//Set UV (Texture) Coordinates
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 1));
	UV0.Add(FVector2D(1, 0));
	UV0.Add(FVector2D(1, 1));

	//Add tile to procedural mesh.
	mapMesh->CreateMeshSection(meshSectionIndex, vertices, indices, normals, UV0, vertexColors, tangents, true);

}

//Sets material for tiles in map individually
void ATileMap::SetTileMaterial(int meshSectionIndex) {
	if (tileMaterial) {
		mapMesh->SetMaterial(meshSectionIndex, tileMaterial);
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Warning: Tile Material not set in editor."));
	}
	
}

void ATileMap::GenerateMap() {
	//Fill map with point data
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map.Add(Point(i, j));
		}
	}

	//Generate tiles
	for (int i = 0; i < map.Num(); i++) {
		CreateTile(map[i].x, map[i].y, i);
		SetTileMaterial(i);
	}
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
	GenerateMap();

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






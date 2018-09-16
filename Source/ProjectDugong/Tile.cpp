// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"

#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

// Sets default values
ATile::ATile(){
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Attach static mesh component
	/*tileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshRef(TEXT("/Engine/BasicShapes/Plane.Plane"));
	if (meshRef.Object) {
		tileMesh->SetStaticMesh(meshRef.Object);
	}*/

	//Set default values
	isOccupied = false;
	actorOnTile = nullptr;

}

//Delegates to default constructor, then sets location and rotation
ATile::ATile(FVector location, FRotator rotation) : ATile() {
	this->SetActorLocation(location);
	this->SetActorRotation(rotation);
}

void ATile::OnConstruction(const FTransform& Transform){
	Super::OnConstruction(Transform);
}

// Called when the game starts or when spawned
void ATile::BeginPlay(){
	Super::BeginPlay();
	
}

// Called every frame
void ATile::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}


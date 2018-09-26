// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseTile.h"
#include "BaseUnit.h"

#include "Components/StaticMeshComponent.h"

#include "GenericPlatformMath.h"

// Sets default values
ABaseTile::ABaseTile(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	tileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tile Mesh"));
	//tileMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	//tileMeshComponent->OnBeginCursorOver.AddDynamic(this, &ABaseTile::CustomOnBeginMouseOver);

	
}
void ABaseTile::Init(Point p, int tileSize, int tilePadding, int index) {
	gridLocation = p;
	this->tileSize = tileSize;
	this->tilePadding = tilePadding;
	this->index = index;
}
// Called when the game starts or when spawned
void ABaseTile::BeginPlay(){
	Super::BeginPlay();
	
}

// Called every frame
void ABaseTile::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

UFUNCTION()
void ABaseTile::CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent) {

}

void ABaseTile::SwapMaterial(UMaterial* newMaterial) {
	UMaterialInstanceDynamic* material = UMaterialInstanceDynamic::Create(newMaterial, this);
	if (material) {
		tileMeshComponent->SetMaterial(0, material);
	}
	else if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("Material swap failed"));
	}
}

bool ABaseTile::InMovementRange(ABaseUnit* unit) {
	Point unitLocation = LocationToPoint(unit->GetActorLocation(), tileSize, tilePadding);
	
	int deltaX = unitLocation.x - gridLocation.x;
	int deltaY = unitLocation.y - gridLocation.y;
	float distance = FGenericPlatformMath::Sqrt(FGenericPlatformMath::Pow(deltaX, 2) + FGenericPlatformMath::Pow(deltaY, 2));
	
	return (distance <= unit->GetMobility()) ? true : false;
}
bool ABaseTile::InSprintRange(ABaseUnit* unit) {
	Point unitLocation = LocationToPoint(unit->GetActorLocation(), tileSize, tilePadding);

	int deltaX = unitLocation.x - gridLocation.x;
	int deltaY = unitLocation.y - gridLocation.y;
	float distance = FGenericPlatformMath::Sqrt(FGenericPlatformMath::Pow(deltaX, 2) + FGenericPlatformMath::Pow(deltaY, 2));

	return (distance <= 2 * unit->GetMobility()) ? true : false;
}
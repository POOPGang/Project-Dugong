// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseTile.h"

#include "TileMap.h"
#include "BaseUnit.h"
#include "UnderworldGameState.h"

#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "GenericPlatformMath.h"

// Sets default values
ABaseTile::ABaseTile(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	tileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tile Mesh"));
	//tileMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	//tileMeshComponent->OnBeginCursorOver.AddDynamic(this, &ABaseTile::CustomOnBeginMouseOver);

	
}
void ABaseTile::Init(Point p, int tileSize, int tilePadding, int index, bool isOccupied) {
	gridLocation = p;
	this->tileSize = tileSize;
	this->tilePadding = tilePadding;
	this->index = index;
	this->isOccupied = isOccupied;
}
// Called when the game starts or when spawned
void ABaseTile::BeginPlay(){
	Super::BeginPlay();

	gameState = Cast<AUnderworldGameState>(GetWorld()->GetGameState());
	if (gameState == nullptr) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Base Unit failed to aquire game state")));
		}
	}
	
}

// Called every frame
void ABaseTile::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void ABaseTile::TileOnClicked(AActor* TouchedActor, FKey ButtonPressed) {
	if (gameState == nullptr) {
		return;
	}
		
	if (gameState->GetActiveUnit() == nullptr) {
		return;
	}

	gameState->SetActiveTile(this);

}

void ABaseTile::CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent) {

}

void ABaseTile::SwapMaterial(UMaterial* newMaterial) {
	UMaterialInstance* material = UMaterialInstanceDynamic::Create(newMaterial, this);
	if (material) {
		tileMeshComponent->SetMaterial(0, material);
	}
	else if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("Material swap failed"));
	}
}

Point ABaseTile::GetGridLocation() {
	return gridLocation;
}

void ABaseTile::Occupy(){
	isOccupied = true;
}

void ABaseTile::DeOccupy(){
	isOccupied = false;
}

bool ABaseTile::GetIsOccupied(){
	return isOccupied;
}

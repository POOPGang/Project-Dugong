// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseTile.h"


// Sets default values
ABaseTile::ABaseTile(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	tileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tile Mesh"));
	tileMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	tileMeshComponent->OnBeginCursorOver.AddDynamic(this, &ABaseTile::CustomOnBeginMouseOver);
}
void ABaseTile::Init(int tileSize, int tilePadding) {
	this->tileSize = tileSize;
	this->tilePadding = tilePadding;
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
	if (GEngine){
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Mouse Over"));
	}
}


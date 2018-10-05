// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseUnit.h"

#include "Types.h"
#include "TileMap.h"
#include "BaseTile.h"
#include "UnderworldGameState.h"

#include "UObject/ConstructorHelpers.h"
#include "Queue.h"
#include "NumericLimits.h"

// Sets default values
ABaseUnit::ABaseUnit(){
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Set default values
	name = "A Base Unit";
	maxHP = hp = 4;
	mobility = 5;
	aim = 65;
	maxAP = ap = 2;
	isMoving = false;
	
}
void ABaseUnit::OnConstruction(const FTransform& Transform) {
	Super::OnConstruction(Transform);

}

// Called when the game starts or when spawned
void ABaseUnit::BeginPlay(){
	Super::BeginPlay();

	gameState = Cast<AUnderworldGameState>(GetWorld()->GetGameState());
	if (gameState  == nullptr) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Base Unit failed to aquire game state")));
		}
		return;
	}

	//Init movement cost array to  for later pathfinding
	for (int i = 0; i < gameState->GetUnderworldMap()->rows; i++) {
		TArray<float> temp;
		temp.Init(TNumericLimits<float>::Max(), gameState->GetUnderworldMap()->cols);
		moveCosts.Add(temp);
	}


	gridLocation = gameState->GetUnderworldMap()->LocationToPoint(this->GetActorLocation());
}

// Called every frame
void ABaseUnit::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseUnit::UnitOnClicked(AActor* TouchedActor, FKey ButtonPressed) {
	if (gameState && ap > 0) {
		gameState->SetActiveUnit(this);
	}
	else {
		//Make unit flash to indicate no AP
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("This unit has no more action points"));
		}
	}
	
}

//Helper function to calculate cost of horizontal and diagonal movements in the underworld
float CalcCost(Point curr, Point target) {
	int deltaX = curr.x - target.x;
	int deltaY = curr.y - target.y;
	
	return (deltaX != 0 && deltaY != 0) ? 1.5 : 1;
}

//Helper function to get the minimum cost for each tile by comparing to nearby tiles.
float MinPathCost(Point targetLoc, TArray<TArray<float>> moveCosts) {
	int rows = moveCosts.Num();
	int cols = moveCosts[0].Num();

	float min = TNumericLimits<float>::Max();
	Point base;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int x = targetLoc.x + i;
			int y = targetLoc.y + j;
			
			//Bounds checking
			if (x < 0 || y < 0 || x >= rows || y >= cols)
				continue;

			if (moveCosts[x][y] < min) {
				base.x = x; 
				base.y = y;
				min = moveCosts[x][y];
			}
		}
	}
	return min + CalcCost(base, targetLoc);
}
void ABaseUnit::PopulateMoveCosts(ATileMap* map) {
	//Defer calculating costs until the unit is picked and can move.
	if (ap == 0) {
		return;
	}
	Point currLoc(map->LocationToPoint(this->GetActorLocation()));
	TQueue<Point> q;
	TArray<TArray<bool>> visited;
	
	//Clear cost array
	for (int i = 0; i < moveCosts.Num(); i++) {
		TArray<float> temp;
		temp.Init(TNumericLimits<float>::Max(), gameState->GetUnderworldMap()->cols);
		moveCosts[i] = temp;
	}
	
	//Init visited array to false for searching
	for (int i = 0; i < map->rows; i++) {
		TArray<bool> temp;
		temp.Init(false, gameState->GetUnderworldMap()->cols);
		visited.Add(temp);
	}

	q.Enqueue(currLoc);
	moveCosts[currLoc.x][currLoc.y] = 0;
	visited[currLoc.x][currLoc.y] = true;

	//This loop performs a breadth first search through the tile map to create a movement cost array for use in move calculations.
	while (!q.IsEmpty()) {		
		q.Peek(currLoc);

		//Add valid neighbors
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				ABaseTile* targetTile = map->operator()(currLoc.x + i, currLoc.y + j);
				
				if (targetTile) { //If the neighbor tile is valid
					Point targetLoc(targetTile->GetGridLocation());

					if (!targetTile->isOccupied && !visited[targetLoc.x][targetLoc.y]) { //And it's not occupied and hasn't been visited
						moveCosts[targetLoc.x][targetLoc.y] = MinPathCost(targetLoc, moveCosts); //Find the cost to move to that tile
						visited[targetLoc.x][targetLoc.y] = true; //Mark it as visited for future loops

						if (moveCosts[targetLoc.x][targetLoc.y] <= mobility * 2) {
							q.Enqueue(targetTile->GetGridLocation()); //Add it to the search queue only if it's within move range anyway
						}
					}
				}
			}
		}
		//Remove Curr location
		q.Pop();
	}
}

TArray<TArray<float>> ABaseUnit::GetMoveCosts() {
	return moveCosts;
}

int ABaseUnit::GetMobility() {
	return mobility;
}
int ABaseUnit::GetActionPoints() {
	return ap;
}

void ABaseUnit::UseActionPoint() {
	ap--;
}

bool ABaseUnit::GetIsMoving() {
	return isMoving;
}

void ABaseUnit::RefreshActionPoints() {
	ap = maxAP;
}

bool ABaseUnit::StartMoving(ABaseTile* target) {
	float movementCost = moveCosts[target->GetGridLocation().x][target->GetGridLocation().y];

	if ( movementCost <= mobility && movementCost > 0) {
		isMoving = true;
		UseActionPoint();
	}
	else if (movementCost <= 2 * mobility && movementCost > 0) {
		isMoving = true;
		UseActionPoint();
		UseActionPoint();
	}
	else {
		isMoving = false;
	}
	return isMoving;
}

void ABaseUnit::StopMoving() {
	isMoving = false;
	gameState->GetUnderworldMap()->ClearMovementTiles();
	PopulateMoveCosts(gameState->GetUnderworldMap());
	gameState->GetUnderworldMap()->DisplayMovementTiles(this);
}
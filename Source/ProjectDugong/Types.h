#pragma once
#include "CoreMinimal.h"
//Simple struct for map points
typedef struct Point {
	int x;
	int y;
	Point() {}
	Point(int i, int j) : x(i), y(j) {}

} Point;


static FVector PointToLocation(int x, int y, int tileSize, int tilePadding) {
	return FVector(x * (tileSize + tilePadding), y * (tileSize + tilePadding), 0);
}
static FVector PointToLocation(Point p, int tileSize, int tilePadding) {
	return FVector(p.x * (tileSize + tilePadding), p.y * (tileSize + tilePadding), 0);
}
static Point LocationToPoint(FVector location, int tileSize, int tilePadding) {
	return Point(location.X / (tileSize + tilePadding), location.Y / (tileSize + tilePadding));
}
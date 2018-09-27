#pragma once
#include "CoreMinimal.h"
//Simple struct for map points
typedef struct Point {
	int x;
	int y;
	Point() {}
	Point(int i, int j) : x(i), y(j) {}

} Point;

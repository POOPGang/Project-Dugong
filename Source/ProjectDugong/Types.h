#pragma once
#include "CoreMinimal.h"
//Simple struct for map points
typedef struct Point {
	int x;
	int y;
	//Defualt constructor
	Point() {}

	//Standard constructor
	Point(int i, int j) : x(i), y(j) {}

	//Copy constructor
	Point(const Point &p) { x = p.x; y = p.y; }

	bool operator ==(const Point other) {
		return ((x == other.x) && (y == other.y));
	}
	bool operator !=(const Point other) {
		return ((x != other.x) || (y != other.y));
	}

} Point;

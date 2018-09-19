#pragma once

//Simple struct for map points
typedef struct Point {
	int x;
	int y;

	Point(int i, int j) : x(i), y(j) {}

} Point;
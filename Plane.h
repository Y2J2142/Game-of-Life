#pragma once
#include "Cell.h"
#include <iostream>
class Plane
{
	int rows;
	int columns;
	Cell** plane;
	Cell** transition_plane;

public:
	Plane(int, int);
	~Plane();
	void step();
	friend std::ostream & operator<<(std::ostream &, const Plane &);
	void randomize_plane();
	bool is_alive();
	void copy(Cell**, Cell**);
};


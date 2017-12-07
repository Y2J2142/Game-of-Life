#include "stdafx.h"
#include "Cell.h"
#include <iostream>

Cell::Cell()
{
	alive = false;
}


Cell::~Cell()
{
}

bool Cell::is_alive()
{
	return alive;
}

void Cell::set_cell(bool a)
{
	alive = a;
}

void Cell::add_neighbour(Cell* c)
{
	neighbours.push_back(c);
}

int Cell::alive_neighbours_counter()
{
	int counter = 0;
	for (Cell* c : neighbours)
		if (c->alive)
			counter++;
	return counter;
}

Cell& Cell::operator=(Cell & c)
{
	this->alive = c.alive;
	return *(this);
}

std::ostream & operator<<(std::ostream & o, const Cell & c)
{
	if (c.alive)
		o << (char)219;
	else
		o << " ";

	return o;
}
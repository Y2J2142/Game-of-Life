#include "stdafx.h"
#include "Plane.h"
#include <random>

Plane::Plane(int r, int c)
{
	

	rows = r;
	columns = c;
	plane = new Cell*[rows];
	transition_plane = new Cell*[rows];
	for (int i = 0; i < rows; i++)
	{
		plane[i] = new Cell[columns];
		transition_plane[i] = new Cell[columns];
	}

	for(int i = 1; i<rows-1;i++)
		for (int j = 1; j < columns-1; j++)
		{
			
			plane[i][j].add_neighbour(&plane[i - 1][j - 1]);
			plane[i][j].add_neighbour(&plane[i - 1][j]);
			plane[i][j].add_neighbour(&plane[i - 1][j + 1]);
			
			plane[i][j].add_neighbour(&plane[i][j - 1]);
			plane[i][j].add_neighbour(&plane[i][j + 1]);
		
			plane[i][j].add_neighbour(&plane[i + 1][j - 1]);
			plane[i][j].add_neighbour(&plane[i + 1][j]);
			plane[i][j].add_neighbour(&plane[i + 1][j + 1]);
		}

}


Plane::~Plane()
{
	for (int i = 0; i < columns; i++)
		delete[] plane[i];
	delete[] plane;
}



void Plane::step()
{
	for (int i = 1; i < rows-1; i++)
		for (int j = 1; j < columns-1; j++)
		{
			int counter = plane[i][j].alive_neighbours_counter();
			//std::cout << "counter :" << counter << std::endl;
			if (!plane[i][j].is_alive() && counter == 3)
				transition_plane[i][j].set_cell(true);
			else if (plane[i][j].is_alive() && counter != 2 && counter != 3)
				transition_plane[i][j].set_cell(false);
			else if (plane[i][j].is_alive() && (counter == 2 || counter == 3))
				transition_plane[i][j].set_cell(true);
			else
				transition_plane[i][j].set_cell(false);
		}
	this->copy(transition_plane, plane);
	
}

std::ostream & operator<<(std::ostream & o, const Plane & p)
{
	for (int i = 0; i < p.rows; i++)
	{
		for (int j = 0; j < p.columns; j++)
			o << p.plane[i][j];
		o << std::endl;
	}
	return o;
}

void Plane::randomize_plane()
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(0, 1); // guaranteed unbiased
	for (int i = 1; i < rows - 1; i++)
		for (int j = 1; j < columns - 1; j++)
			if(uni(rng) == 0)
				plane[i][j].set_cell(true);
			else
				plane[i][j].set_cell(false);
}


bool Plane::is_alive()
{
	for (int i = 1; i < rows - 1; i++)
		for (int j = 1; j < columns - 1; j++)
			if (plane[i][j].is_alive())
				return true;
	return false;
}

void Plane::copy(Cell** source, Cell** dest)
{
	for (int i = 1; i < rows - 1; i++)
		for (int j = 1; j < columns - 1; j++)
			dest[i][j] = source[i][j];
}
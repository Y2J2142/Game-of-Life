#pragma once
#include <vector>
class Cell
{
private: 
	bool alive;
	std::vector<Cell*> neighbours;
public:
	Cell();
	~Cell();
	bool is_alive();
	void set_cell(bool);
	void add_neighbour(Cell*);
	int alive_neighbours_counter();
	Cell& operator=(Cell &);
	friend std::ostream & operator<<(std::ostream &, const Cell &);
};


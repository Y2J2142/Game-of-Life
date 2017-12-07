#include "Plane.h"
#include "Cell.h"
#include <iostream>
#include <windows.h>

int main()
{
	int rows, columns;
	std::cout << "input number of rows and collumns" << std::endl;
	std::cin >> rows >> columns;
	Plane plane(rows, columns);
	plane.randomize_plane();
	do
	{
		system("cls");
		std::cout << plane << std::endl;
		plane.step();
		Sleep(300);
		
		
	} while (plane.is_alive());
	system("pause");
    return 0;
}

       
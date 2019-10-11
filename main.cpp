#include <iostream>
#include "Header.h"

int main()
{
	OpenFile file("map.txt");
	Sudoku sud(file.input_map);
	print_mapp(sud.map_sudoku);

	system("pause");
	return 0;
}
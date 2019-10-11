#include <iostream>
#include <fstream>
#include "Header.h"

Sudoku::Sudoku(cage input_map[9][9]) {
	Node *tree = NULL;
	decision(tree, 0, 0, input_map);
}

void Sudoku::decision(Node *&tree, int i, int j, cage map[9][9])
{
	if ((j == 1) & (i == 9))
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				map_sudoku[i][j] = map[i][j];
			}
		return;
	}

	if (map[i][j].filled)
		if (j == 8)
			decision(tree, i + 1, 0, map);
		else
			decision(tree, i, j + 1, map);

	if (NULL == tree)
	{
		tree = new Node;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				tree->map_sudoku[i][j] = map[i][j];
			}

		for (int k = 1; k < 10; k++)
		{
			if (!check(tree->map_sudoku, i, j, k))
				continue;
			tree->map_sudoku[i][j].rnum = k;
			tree->map_sudoku[i][j].filled = true;

			if (j == 8)
			{
				tree->next[k - 1] = NULL;
				decision(tree->next[k - 1], i + 1, 0, tree->map_sudoku);
			}
			else
			{
				tree->next[k - 1] = NULL;
				decision(tree->next[k - 1], i, j + 1, tree->map_sudoku);
			}
		}
		delete tree;
	}
}


bool Sudoku::check_gorizontle(cage mas[9][9], int i, int num)
{
	for (int k = 0; k < 9; k++)
	{
		if (mas[i][k].filled)
			if (mas[i][k].rnum == num)
				return false;
	}
	return true;
}

bool Sudoku::check_verticale(cage mas[9][9], int j, int num)
{
	for (int k = 0; k < 9; k++)
	{
		if (mas[k][j].filled)
			if (mas[k][j].rnum == num)
				return false;
	}
	return true;
}

bool Sudoku::check_box(cage mas[9][9], int i, int j, int num)
{
	for (int k = i; k < (i + 3); k++)
		for (int g = j; g < (j + 3); g++)
		{
			if (mas[k][g].filled)
				if (mas[k][g].rnum == num)
					return false;
		}
	return true;
}

bool Sudoku::check(cage mas[9][9], int i, int j, int num)
{
	if (!check_gorizontle(mas, i, num))
		return false;
	if (!check_verticale(mas, j, num))
		return false;
	i = 3 * (i / 3);
	j = 3 * (j / 3);
	if (!check_box(mas, i, j, num))
		return false;
	return true;
}

OpenFile::OpenFile(const char* nameFile){
	std::ifstream file(nameFile);
	char symbol;

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			file >> symbol;
			if (symbol != '_')
			{
				input_map[i][j].rnum = int(symbol) - 48;
				input_map[i][j].filled = true;
			}
			else
			{
				input_map[i][j].filled = false;
			}
		}
	file.close();
}



void print_mapp(cage map[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (map[i][j].filled)
				std::cout << map[i][j].rnum << ' ';
			else
				std::cout << '_';
		}
		std::cout << std::endl;
	}
}
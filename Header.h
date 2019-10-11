#pragma once

struct cage {
	bool filled;					// true - заполнено false - свободно
	int rnum;
};

struct Node {
	cage map_sudoku[9][9];
	int num;
	Node *next[9];
};

class Sudoku {
public:
	cage map_sudoku[9][9];
	Sudoku(cage input_map[9][9]);
private:
	void decision(Node *&tree, int i, int j, cage map[9][9]);
	bool check_gorizontle(cage mas[9][9], int i, int num);
	bool check_verticale(cage mas[9][9], int j, int num);
	bool check_box(cage mas[9][9], int i, int j, int num);
	bool check(cage mas[9][9], int i, int j, int num);
};

class OpenFile {
public:
	cage input_map[9][9];
	OpenFile(const char* nameFile);
};

void print_mapp(cage map[9][9]);
#pragma once

#include "Cell.h"

class Board {

public:

	Board(int rows, int cols);
	~Board();

	void print();
	void reveal(int row, int col);

	int get_status();

private:

	bool is_cell(int row, int col);

	// Count number of mines around cell
	int count_mines(int row, int col);

	int rows;
	int cols;

	int status;

	int num_mines;
	int num_revealed;

	Cell** cells;

};
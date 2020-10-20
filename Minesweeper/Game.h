#pragma once

#include "Cell.h"

class Game {

public:

	Game(int height, int width);
	~Game();

	void print_board();
	void reveal(int row, int col);


private:

	bool is_cell(int row, int col);
	
	// Count number of mines around cell
	int count_mines(int row, int col);

	int rows;
	int cols;

	Cell** cells;

};
#pragma once

#include "Cell.h"

class Game {

public:

	Game(int height, int width);
	~Game();

	void print();


private:

	int rows;
	int cols;

	Cell** cells;
	Cell* data;

};
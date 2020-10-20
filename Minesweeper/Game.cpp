
#include "Game.h"

#include <stdlib.h>
#include <iostream>

#include <new>

Game::Game(int height, int width) {

	rows = height;
	cols = width;

	cells = new Cell * [rows];
	for (int i = 0; i < rows; i++)
		cells[i] = new Cell[cols];

};

Game::~Game() {
	for (int i = 0; i < rows; i++)
		delete cells[i];
	delete cells;
};

void Game::print() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << cells[i][j].reveal();
		}
		std::cout << std::endl;
	}
};
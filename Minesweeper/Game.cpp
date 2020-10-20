
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

void Game::reveal(int row, int col) {

	if (!cells[row][col].is_revealed()) {

		cells[row][col].reveal();
		int mines_count = count_mines(row, col);
		cells[row][col].assign(mines_count);

		std::cout << "row: " << row << " col: " << col << " mines_count: " << mines_count << std::endl;

		// If there are no mines, reveal neighbors
		if (mines_count == 0) {
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if (is_cell(row + i, col + j)) {
						if (!cells[row + i][col + j].is_revealed()) {
							reveal(row + i, col + j);
						}
					}
				}
			}
		}

	}

};

int Game::count_mines(int row, int col) {

	int mines_count = 0;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (is_cell(row + i, col + j)) {
				if (cells[row + i][col + j].is_mine()) {
					mines_count++;
				}
			}
		}
	}

	return mines_count;
}

bool Game::is_cell(int row, int col) {
	if (row < rows && row >= 0 && col < cols && col >= 0)
		return true;
	else
		return false;
};

void Game::print_board() {
	for (int i = 0; i < rows; i++) {
		std::cout << i << " ";
		for (int j = 0; j < cols; j++) {
			if (cells[i][j].is_revealed()) {
				std::cout << "[" << cells[i][j].get_value() << "]";
			}
			else {
				std::cout << "[ ]";
			}
		}
		std::cout << std::endl;
	}

	std::cout << "   ";
	for (int i = 0; i < cols; i++) {
		std::cout << i << "  ";
	}

};
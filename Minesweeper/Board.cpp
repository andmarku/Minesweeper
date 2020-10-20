
#include "Board.h"

#include <stdlib.h>
#include <iostream>
#include <new>

Board::Board(int rows, int cols) {

	this->rows = rows;
	this->cols = cols;


	cells = new Cell * [rows];
	for (int i = 0; i < rows; i++)
		cells[i] = new Cell[cols];

	status = 0;
	num_mines = 0;
	num_revealed = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			num_mines += cells[i][j].is_mine();

};

Board::~Board() {
	for (int i = 0; i < rows; i++)
		delete cells[i];
	delete cells;
};

void Board::reveal(int row, int col) {

	if (is_cell(row, col)) {
		if (!cells[row][col].is_revealed()) {

			cells[row][col].reveal();

			num_revealed++;

			// Lost the board
			if (cells[row][col].is_mine()) {
				status = 1;
				return;
			}

			// Won the board
			if (num_revealed == rows * cols - num_mines) {
				status = 2;
				return;
			}

			int mines_count = count_mines(row, col);

			cells[row][col].assign(mines_count);

			// If there are no mines, reveal neighbors
			if (mines_count == 0)
				for (int i = -1; i <= 1; i++)
					for (int j = -1; j <= 1; j++)
						reveal(row + i, col + j);
		}
	}
};

int Board::count_mines(int row, int col) {

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
};

bool Board::is_cell(int row, int col) {
	if (row < rows && row >= 0 && col < cols && col >= 0)
		return true;
	else
		return false;
};

void Board::print() {
	for (int i = 0; i < rows; i++) {
		std::cout << i << " ";
		for (int j = 0; j < cols; j++) {
			if (cells[i][j].is_revealed()) {
				if (cells[i][j].is_mine()) {
					std::cout << "[x]";
				}
				else {
					std::cout << "[" << cells[i][j].get_value() << "]";
				}
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

int Board::get_status() {
	return status;
};
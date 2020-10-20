#include "Game.h"

#include <iostream>
#include <new>

Game::Game(int rows, int cols) {

	board = new Board(rows, cols);

	int x, y;

	board->print();

	while (board->get_status() == 0) {

		std::cout << "\nEnter row: ";

		std::cin >> x;

		std::cout << "Enter col: ";

		std::cin >> y;

		board->reveal(x, y);

		board->print();

		if (board->get_status() == 2) {
			std::cout << "\nYou won!\n";
		}
		if (board->get_status() == 1) {
			std::cout << "\nYou lost!\n";
		}
	}
};





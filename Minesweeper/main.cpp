#include <iostream>

#include "Game.h"

int main() {

    std::cout << "Welcome to Minesweeper!\n";

    Game game(10, 10);

    std::cout << "Printing board\n--------------\n";
    game.print();
    std::cout << "--------------\n";

    return 0;

}
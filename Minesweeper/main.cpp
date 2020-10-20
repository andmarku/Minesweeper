#include <iostream>

#include "Game.h"

int main() {

    std::cout << "Welcome to Minesweeper!\n";

    Game game(10, 10);

    game.print_board();
    
    game.reveal(4, 4);

    game.print_board();

    return 0;

}
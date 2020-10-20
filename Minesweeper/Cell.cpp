#include "Cell.h"

#include <cstdlib>

Cell::Cell() {

	value = 0;

	if (rand() % 100 < percentage * 100) { mine = true; }
	else { mine = false; }

	revealed = false;

};

bool Cell::is_revealed() {
	return revealed;
};

bool Cell::is_mine() {
	return mine;
};

void Cell::reveal() {
	revealed = true;
};

void Cell::assign(int number) {
	value = number;
};

int Cell::get_value() {
	return value;
};


// The percentage of being a mine
const double Cell::percentage = 0.1;

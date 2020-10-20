#include "Cell.h"

#include <cstdlib>

Cell::Cell() {

	value = 0;

	if (rand() % 100 < percentage * 100) { mine = true; }
	else { mine = false; }

	revealed = false;

}

bool Cell::reveal() {
	revealed = true;
	return mine;
}

void Cell::assign(int number) {
	value = number;
}

// The percentage of being a mine
const double Cell::percentage = 0.1;

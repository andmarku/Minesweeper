#pragma once

class Cell {

public:

	Cell();

	bool reveal();
	void assign(int number);

private:

	static double const percentage;

	int value;

	bool mine;
	bool revealed;

};
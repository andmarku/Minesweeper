#pragma once

class Cell {

public:

	Cell();

	bool is_revealed();
	bool is_mine();

	int get_value();

	void reveal();
	void assign(int number);

private:

	static double const percentage;

	int value;

	bool mine;

	bool revealed;

};
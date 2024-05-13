#pragma once
#include "Shape.h"

class Square : public Shape
{
	//string _type = "Square";
	char _type[15] = "Square";
	int _x;
	int _y;
	int _side;
public:
	Square();
	Square(int x, int _y, int side);
	Square(const Square& obj);

	virtual Square* clone() const;



	Square& operator=(const Square& obj);
	string getType();

	void save();
	void load(FILE* file);
	void show();
};


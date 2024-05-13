#pragma once
#include "Shape.h"

class Circle : public Shape
{
	//string _type = "Circle";
	char _type[15] = "Circle";
	int _x;
	int _y;
	int _radius;
public:
	Circle();
	Circle(int x, int y, int radius);
	Circle(const Circle& obj);

	virtual Circle* clone() const;

	Circle& operator=(const Circle& obj);
	string getType();

	void save();
	void load(FILE* file);
	void show();
};


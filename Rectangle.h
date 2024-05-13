#pragma once
#include "Shape.h"


class Rectangle : public Shape
{
	//string _type = "Rectangle";
	char _type[15] = "Rectangle";
	int _x;
	int _y;
	int _length;
	int _height;
public:
	Rectangle();
	Rectangle(int x, int y, int length, int height);
	Rectangle(const Rectangle& obj);

	virtual Rectangle* clone() const;

	Rectangle& operator=(const Rectangle& obj);
	string getType();

	void save();
	void load(FILE* file);
	void show();

};


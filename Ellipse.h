#pragma once
#include "Shape.h"

class Ellipse : public Shape
{
	//string _type = "Ellipse";
	char _type[15] = "Ellipse";
	int _x;
	int _y;
	int _height;
	int _length;
public:
	Ellipse();
	Ellipse(int x, int y, int height, int length);
	Ellipse(const Ellipse& obj);

	virtual Ellipse* clone() const;

	Ellipse& operator=(const Ellipse& obj);
	string getType();

	void save();
	void load(FILE* file);
	void show();

};


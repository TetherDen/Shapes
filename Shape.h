#pragma once
#include "config.h"
#include <iostream>
using namespace std;

class Shape
{
public:
	virtual void show() = 0;	// ЧИСТО вирт метод
	virtual void save() = 0;
	virtual void load(FILE* file) = 0;

	virtual string getType() = 0;
	virtual Shape* clone() const = 0;
	//virtual Shape& operator=(const Shape& obj) {};

	/*virtual ~Shape() = 0;*/   // Или virtual ~Shape() {} ?
};


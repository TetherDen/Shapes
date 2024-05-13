#include "Circle.h"

Circle::Circle()
	: _x(0),_y(0),_radius(0)
{
}

Circle::Circle(int x, int y, int radius)
	:_x(x),_y(y),_radius(radius)
{
}

Circle::Circle(const Circle& obj)
{
	_x = obj._x;
	_y = obj._y;
	_radius = obj._radius;
}

Circle* Circle::clone() const
{
	return new Circle(*this);
}

Circle& Circle::operator=(const Circle& obj)
{
	if (this != &obj)
	{
		_x = obj._x;
		_y = obj._y;
		_radius = obj._radius;
	}
	return *this;
}

string Circle::getType()
{
	return _type;
}


void Circle::save()
{
	FILE* file;
	if (fopen_s(&file, PATH, "ab") == 0)
	{
		fwrite(&_type, sizeof(_type), 1, file);
		fwrite(&_x, sizeof(_x), 1, file);
		fwrite(&_y, sizeof(_y), 1, file);
		fwrite(&_radius, sizeof(_radius), 1, file);
		fclose(file);
	}
}

void Circle::load(FILE* file)
{
	fread(&_x, sizeof(_x), 1, file);
	fread(&_y, sizeof(_y), 1, file);
	fread(&_radius, sizeof(_radius), 1, file);
}

void Circle::show()
{
	cout << _type << endl << " X: " << _x << "	Y: " << _y << "	Radius: " << _radius << endl;

}

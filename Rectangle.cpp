#include "Rectangle.h"

Rectangle::Rectangle() 
	: _x(0), _y(0),_length(0),_height(0)
{
}

Rectangle::Rectangle(int x, int y, int length, int height)
	: _x(x),_y(y),_length(length),_height(height)
{
}

Rectangle::Rectangle(const Rectangle& obj)
{
	_x = obj._x;
	_y = obj._y;
	_length = obj._length;
	_height = obj._height;
}

Rectangle* Rectangle::clone() const
{
	return new Rectangle(*this);
}

Rectangle& Rectangle::operator=(const Rectangle& obj)
{
	if (this != &obj)
	{
		_x = obj._x;
		_y = obj._y;
		_length = obj._length;
		_height = obj._height;
	}
	return *this;
}

string Rectangle::getType()
{
	return _type;
}

void Rectangle::save()
{
	FILE* file;
	if (fopen_s(&file, PATH, "ab") == 0)
	{
		fwrite(&_type, sizeof(_type), 1, file);
		fwrite(&_x, sizeof(_x), 1, file);
		fwrite(&_y, sizeof(_y), 1, file);
		fwrite(&_length, sizeof(_length), 1, file);
		fwrite(&_height, sizeof(_height), 1, file);
		fclose(file);
	}
}

void Rectangle::load(FILE* file)
{
	fread(&_x, sizeof(_x), 1, file);
	fread(&_y, sizeof(_y), 1, file);
	fread(&_length, sizeof(_length), 1, file);
	fread(&_height, sizeof(_height), 1, file);
}

void Rectangle::show()
{
	cout << _type << endl << " X: " << _x << "	Y: " << _y << "	Length: " << _length<<"	Height: "<<_height << endl;
}

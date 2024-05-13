#include "Ellipse.h"

Ellipse::Ellipse()
	: _x(0),_y(0),_height(0),_length(0)
{
}

Ellipse::Ellipse(int x, int y, int height, int length)
	: _x(x),_y(y),_height(height),_length(length)
{
}

Ellipse::Ellipse(const Ellipse& obj)
{
	_x = obj._x;
	_y = obj._y;
	_length = obj._length;
	_height = obj._height;
}

Ellipse* Ellipse::clone() const
{
	return new Ellipse(*this);
}

Ellipse& Ellipse::operator=(const Ellipse& obj)
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

string Ellipse::getType()
{
	return _type;
}

void Ellipse::save()
{
	FILE* file;
	if (fopen_s(&file, PATH, "ab") == 0)
	{
		fwrite(&_type, sizeof(_type), 1, file);
		fwrite(&_x, sizeof(_x), 1, file);
		fwrite(&_y, sizeof(_y), 1, file);
		fwrite(&_height, sizeof(_height), 1, file);
		fwrite(&_length, sizeof(_length), 1, file);
		fclose(file);
	}
}

void Ellipse::load(FILE* file)
{
	fread(&_x, sizeof(_x), 1, file);
	fread(&_y, sizeof(_y), 1, file);
	fread(&_length, sizeof(_length), 1, file);
	fread(&_height, sizeof(_height), 1, file);
}

void Ellipse::show()
{
	cout << _type << endl << " X: " << _x << "	Y: " << _y << "	Length: " << _length << "	Height: " << _height << endl;
}

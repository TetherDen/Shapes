#include "Square.h"

Square::Square() : _x(0),_y(0),_side(0)
{
}

Square::Square(int x, int y, int side): _x(x), _y(y), _side(side)
{
}

Square::Square(const Square& obj)
{
	_x = obj._x;
	_y = obj._y;
	_side = obj._side;
	//_type = obj._type;
}

Square* Square::clone() const
{
	return new Square(*this);
}

Square& Square::operator=(const Square& obj)
{
	if (this != &obj)
	{
		_x = obj._x;
		_y = obj._y;
		_side = obj._side;
		//_type = obj._type;
	}
	return *this;
}

string Square::getType()
{
	return _type;
}

void Square::save()
{
	FILE* file;
	if (fopen_s(&file, PATH, "ab") == 0)
	{
		fwrite(&_type, sizeof(_type), 1, file);
		fwrite(&_x, sizeof(_x), 1, file);
		fwrite(&_y, sizeof(_y), 1, file);
		fwrite(&_side, sizeof(_side), 1, file);
		fclose(file);
	}
}
void Square::load(FILE* file)
{
	//fread(&_type, sizeof(_type), 1, file);
	fread(&_x, sizeof(_x), 1, file);
	fread(&_y, sizeof(_y), 1, file);
	fread(&_side, sizeof(_side), 1, file);
	//fclose(file);
}

void Square::show()
{
	cout << _type << endl << " X: " << _x << "	Y: " << _y << "	Side: " << _side << endl;
}

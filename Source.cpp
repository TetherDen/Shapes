#include <iostream>
using namespace std;
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "config.h"
#include <cstdio>
#include <string>


#include <fstream>



void add(Shape** arr, Shape* obj, int& size, int capacity)
{
	if (size < capacity)
	{
		arr[size] = obj;   // присваивает в массив адресса
		size++;
	}
}

void arrShow(Shape** arr, int size)
{
	for (int  i = 0; i < size; i++)
	{
		arr[i]->show();
	}
}

void arrSave(Shape** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->save();
	}
}

void deleteArr(Shape**& arr, int& size)
{
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
	arr = nullptr;
}

void arrPlusSize(Shape**& arr, int& size)
{

	Shape** newArr = new Shape * [size+1];  // надо бы +10 или х2 и в нуллптр пустые

	for (int i = 0; i < size; i++)
	{								
		newArr[i] = arr[i]->clone();    // clone
	}
	deleteArr(arr, size);       
	size++;
	arr = newArr;

}


Shape** arrLoad(FILE* file, int& s)
{
	int size = 0;
	Shape** arr2 = new Shape * [size];  //  0?
	int i = 0;
	char type[15];
	while (fread(&type, sizeof(type), 1, file) == 1)
	{
		arrPlusSize(arr2, size);
		if (strcmp(type, "Square") == 0)
		{
			Shape* sh = new Square;
			sh->load(file);
			arr2[i] = sh;
		}
		else if (strcmp(type, "Rectangle") == 0)
		{
			Shape* sh = new Rectangle;
			sh->load(file);
			arr2[i] = sh;
		}
		else if (strcmp(type, "Circle") == 0)
		{
			Shape* sh = new Circle;
			sh->load(file);
			arr2[i] = sh;
		}
		else if (strcmp(type, "Ellipse") == 0)
		{
			Shape* sh = new Ellipse;
			sh->load(file);
			arr2[i] = sh;
		}
		else
		{
			continue;
		}
		i++;
	}
	s = size;
	return arr2;
}

int main()
{
	int capacity = 10;
	int size = 0;
	Shape** arr = new Shape * [capacity];

	Shape* sh1;
	sh1 = new Square(3,5, 10);
	//sh->show();
	sh1->save();  // save
	add(arr, sh1, size, capacity);

	Shape* sh2;
	sh2 = new Rectangle(5, 5, 10, 10);
	//sh->show();
	sh2->save();
	add(arr, sh2, size, capacity);

	Shape* sh3;
	sh3 = new Circle(7, 7, 7);
	//sh->show();
	sh3->save();
	add(arr, sh3, size, capacity);

	Shape* sh4;
	sh4 = new Ellipse(1, 1, 1, 1);
	//sh->show();
	sh4->save();
	add(arr, sh4, size, capacity);

	cout <<"sh load: " << endl;

	arrShow(arr, size);
	arrSave(arr, size);

	cout << endl << "Arr Load: " << endl;
	Shape** arr2 = nullptr;
	int sizeArr2 = 0;
	FILE* file;
	if (fopen_s(&file, PATH, "rb") == 0)
	{
		arr2 = arrLoad(file,sizeArr2);
		fclose(file);
	}

	arrShow(arr2, sizeArr2);

	// TODO очистка Arr2 !!
	deleteArr(arr2, sizeArr2);

	delete sh1;
	delete sh2;
	delete sh3;
	delete sh4;
	delete[] arr;

	return 0;
}
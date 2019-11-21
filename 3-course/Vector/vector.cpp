#include<iostream>
#include "vector.h"

using std::cout;
using std::cin;
using std::endl;

Vector::Vector(int vectorDimension)
{
	if (vectorDimension < 0)
	{
		this->vectorDimension = vectorDimension;
		this->coordinates = new double[vectorDimension];
		for (int i = 0; i < vectorDimension; i++)
		{
			this->coordinates[i] = 0;
		}
	}
	else
	{
		cout << "ERROR*: vector dimension cannot be less than 0" << endl;
	}
}


Vector::Vector(const Vector& obj)
{
	this->vectorDimension = obj.vectorDimension;
	this->coordinates = new double[obj.vectorDimension];

	for (int i = 0; i < obj.vectorDimension; i++)
	{
		this->coordinates[i] = obj.coordinates[i];
	}

}

Vector::~Vector()
{
	delete[] coordinates;
}

void Vector::add(int vectorDimension, double* newVector)
{
	if (vectorDimension < 1)
	{
		cout << "*ERROR*: vector dimension cannot be less than 1" << endl;
	}
	else
	{
		this->vectorDimension = vectorDimension;
		this->coordinates = new double[vectorDimension];
		for (int i = 0; i < vectorDimension; i++)
		{
			coordinates[i] = newVector[i];
		}
	}
}

void Vector::print()
{
	cout << "Dimension: " << this->vectorDimension << endl;
	cout << "Vector: (";
	for (int i = 0; i < this->vectorDimension; i++)
	{
		cout << this->coordinates[i];
		if (i < this->vectorDimension - 1)
			cout << ", ";
	}
	cout << " )" << endl;
}
#include<iostream>
#include "vector.h"

using std::cout;
using std::cin;
using std::endl;

Vector::Vector(int vectorDimension)
{
	if (vectorDimension > 0)
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
	cout << "\tDimension: " << this->vectorDimension << endl;
	cout << "\tCoordinates: (";
	for (int i = 0; i < this->vectorDimension; i++)
	{
		cout << this->coordinates[i];
		if (i < this->vectorDimension - 1)
			cout << ", ";
	}
	cout << ")" << endl;
}

Vector operator+(Vector obj1, double num)
{
	Vector obj;
	obj.vectorDimension = obj1.vectorDimension;
	obj.coordinates = new double[obj.vectorDimension];
	for(int i = 0; i < obj.vectorDimension; i++)
	{
		obj.coordinates[i] = obj1.coordinates[i] + num;
	}
	return obj;
}

Vector operator-(Vector obj1, double num)
{
	Vector obj;
	obj.vectorDimension = obj1.vectorDimension;
	obj.coordinates = new double[obj.vectorDimension];
	for(int i=0; i < obj.vectorDimension; i++)
	{
		obj.coordinates[i] = obj1.coordinates[i] - num;
	}
	return obj;
}

Vector Vector::operator+(Vector obj1)
{
	if(obj1.vectorDimension == vectorDimension)
		{
			Vector obj;
			obj.vectorDimension = obj1.vectorDimension;
			obj.coordinates = new double[obj1.vectorDimension];
			for(int i=0; i < obj1.vectorDimension; i++)
			{
				obj.coordinates[i] = coordinates[i] + obj1.coordinates[i];
			}
			return obj;
		}
	else
		{
			cout<<"*ERROR* Non equal value!"<<endl;
			Vector v(1);
			return v;
		}
}

Vector Vector::operator-(Vector obj1)
{
	int i;
	if(vectorDimension == obj1.vectorDimension)
		{
			Vector obj;
			obj.vectorDimension = obj1.vectorDimension;
			obj.coordinates = new double[obj1.vectorDimension];
			for(i=0; i < obj1.vectorDimension; i++)
			{
				obj.coordinates[i] = coordinates[i] - obj1.coordinates[i];
			}
			return obj;
		}
	else
		{
			cout<<"*ERROR* Non equal value!"<<endl;
			Vector v(1);
			return v;
		}
}

Vector& Vector::operator=(const Vector& obj1)
{
	if(vectorDimension >= 1)
	{
		delete [] coordinates;
	}
	coordinates = new double[obj1.vectorDimension];
	vectorDimension = obj1.vectorDimension;
	for(int i=0; i < obj1.vectorDimension; i++)
	{
		coordinates[i] = obj1.coordinates[i];
	}

	return *this;

}

bool Vector::operator==(Vector obj1)
{
    if(vectorDimension == obj1.vectorDimension)
	{
        for(int i=0; i < vectorDimension; i++)
		{
            if(coordinates[i] != obj1.coordinates[i])
			{
            	return false;
			}
		}
		return true;
	}
	else
        return false;
}

bool Vector::operator!=(Vector obj1)
{
    return !(*this == obj1);
    //return !(this->operator==(obj1));//
    /*if(vectorDimension == obj1.vectorDimension)
	{
        for(int i=0; i<vectorDimension; i++)
		{
            if(coordinates[i] == obj1.coordinates[i])
			{
                return false;
			}
			else
			{
                return true;
			}
		}
	}
	else
	{
        return true;
	}*/
}

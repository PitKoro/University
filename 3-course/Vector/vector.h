#pragma once
class Vector
{
private:
	int vectorDimension; // Размерность вектора
	double* coordinates; // Указатель на вектор
public:
	Vector() {};
	Vector(int vectorDimension);
	Vector(const Vector& obj); // Конструктор копирования
	~Vector();
	void add(int vectorDimension, double* newVector);
	void print();
};


#pragma once
class Vector
{
private:
	int vectorDimension; // Размерность вектора
	double* coordinates; // Указатель на вектор
public:
	Vector() {
		vectorDimension = 0;
		coordinates = new double[1];
	};
	Vector(int vectorDimension);
	Vector(const Vector& obj); // Конструктор копирования
	~Vector();
	void add(int vectorDimension, double* newVector);
	void print();
	Vector operator+(Vector obj1);
	Vector operator-(Vector obj1);
	Vector& operator=(const Vector& obj1);
	bool operator==(Vector obj1);
    bool operator!=(Vector obj1);
	friend Vector operator+(Vector obj, double num);
	friend Vector operator-(Vector obj, double num);
};


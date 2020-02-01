#pragma once

#include <iostream>
#include "Figure.h"

using namespace std;



class Boublik : public Figure
{
public:
	Boublik(int R, int G, int B, int x, int y, int smallRadius, int bigRadius);
	virtual ~Boublik();

	virtual void calcParams(float& perimeter, float& area) const; // вычислить периметр и площадь фигуры
	void setSizes(int smallRadius, int bigRadius); // Изменение размера фигуры
	int getSmallRadius() const;
	int getBigRadius() const;
	

private:
	int smallRadius; //Радиус внутреннего круга
	int bigRadius; // Радиус внешнего круга
protected:
	virtual void draw();
};

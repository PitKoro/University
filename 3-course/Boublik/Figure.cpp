#include<iostream>
#include "Figure.h"
using namespace std;


Figure::Figure(int c, int x, int y)
{
	this->c = c;
	this->x = x;
	this->y = y;
	visible = false;
}

Figure::~Figure()
{
}

/// Если фигура видимая - сдвигаем параметры на дельту
void Figure::move(int dx, int dy)
{
	if (this->visible == true)
	{
		this->x += dx;
		this->y += dy;
		draw();
	}
}

// Если фигура видимая - устанавливаем цвет фигуры
void Figure::setBorderColor(int c)
{
	if (this->visible == true)
	{
		this->c = c;
		draw();
	}
	else
	{
		cout << "*ERROR*: The figure is invisible\n";
	}

}

int Figure::getBorderColor() const
{
	return this->c;
}

void Figure::setVisible(bool isVisible)
{
	this->visible = isVisible;
	if (this->visible == true)
	{
		draw();
	}
	
}

bool Figure::isVisible() const
{
	return this->visible;
}

Point Figure::getCenter() {
	Point center;
	center.x = x;
	center.y = y;
	return center;
}
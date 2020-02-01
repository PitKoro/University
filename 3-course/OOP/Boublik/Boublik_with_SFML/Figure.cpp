#include<iostream>
#include "Figure.h"
using namespace std;


Figure::Figure(int R, int G, int B, int x, int y)
{
	this->R = R;
	this->G = G;
	this->B = B;
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
void Figure::setBorderColor(int R, int G, int B)
{
	if (this->visible == true)
	{
		this->R = R;
		this->G = G;
		this->B = B;
		draw();
	}
	else
	{
		cout << "*ERROR*: The figure is invisible\n";
	}

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

BorderColor Figure::getBorderColor()
{
	BorderColor border_color;
	border_color.R = R;
	border_color.G = G;
	border_color.B = B;
	return border_color;
}
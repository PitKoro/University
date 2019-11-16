#include "Figure.h"

void Figure::draw() const
{
}

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
	}
}

// Если фигура видимая - устанавливаем цвет фигуры
void Figure::setBorderColor(int c)
{
	if (this->visible == true)
	{
		this->c = c;
	}
}

int Figure::getBorderColor() const
{
	return this->c;
}

void Figure::setVisible(bool isVisible)
{
	this->visible = isVisible;
}

bool Figure::isVisible() const
{
	return this->visible;
}

void Figure::calcParams(float& perimeter, float& area) const
{
}

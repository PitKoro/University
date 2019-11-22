#include "FilledBoublik.h"

FilledBoublik::FilledBoublik(int c, int x, int y, int smallRadius, int bigRadius, int f) :Boublik(c, x, y, smallRadius, bigRadius)
{
	this->f = f;
}

FilledBoublik::~FilledBoublik()
{
}

void FilledBoublik::setFillColor(int f)
{
	this->f = f;
	if (isVisible()) {
		draw();
	}
}

void FilledBoublik::setBorderColor(int c)
{
	// Если цвет границ и заполнения не равны, меняем цвет границ.
	if (c != f)
	{
		Boublik::setBorderColor(c);
		cout << " Border Color " << getBorderColor() << endl;
		draw();
	}
}

int FilledBoublik::getFillColor()
{
	return this->f;
}

void FilledBoublik::draw()
{
	cout << " The FILLED BOUBLIK draw " << endl;
	cout << " Center (x;y): (" << x << ";" << y << ") " << endl;
	cout << " Outer circle radius: " << getBigRadius() << endl;
	cout << " Inner circle radius: " << getSmallRadius() << endl;
	cout << " Visible: " << isVisible() << endl;
	cout << " Border color: " << getBorderColor() << endl;
	cout << " Fill color: " << getFillColor() << endl;
	cout << " END " << endl;
	cout << " " << endl;
}
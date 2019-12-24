#include "FilledBoublik.h"

FilledBoublik::FilledBoublik(int R, int G, int B, int x, int y, int smallRadius, int bigRadius, int RED, int GREEN, int BLUE) :Boublik(R, B, G, x, y, smallRadius, bigRadius)
{
	this->RED = RED;
	this->GREEN = GREEN;
	this->BLUE = BLUE;
}

FilledBoublik::~FilledBoublik()
{
}

void FilledBoublik::setFillColor(int R, int G, int B)
{
	this->RED = R;
	this->GREEN = G;
	this->BLUE = B;
	if (isVisible()) {
		draw();
	}
}

void FilledBoublik::setBorderColor(int R, int G, int B)
{
	// Меняем цвет границ.
	Boublik::setBorderColor(R, G, B);
	
}


void FilledBoublik::draw()
{
	cout << " The FILLED BOUBLIK draw " << endl;
	cout << " Center (x;y): (" << x << ";" << y << ") " << endl;
	cout << " Outer circle radius: " << getBigRadius() << endl;
	cout << " Inner circle radius: " << getSmallRadius() << endl;
	cout << " Visible: " << isVisible() << endl;
	cout << " Border color: (" << R << ";" << G << ";" << B << ") " << endl;
	cout << " Fill color: (" << RED << ";" << GREEN << ";" << BLUE << ") " << endl;
	cout << " END " << endl;
	cout << " " << endl;
}

FillColor FilledBoublik::getFillColor()
{
	FillColor fill_color;
	fill_color.RED = RED;
	fill_color.GREEN = GREEN;
	fill_color.BLUE = BLUE;
	return fill_color;
}
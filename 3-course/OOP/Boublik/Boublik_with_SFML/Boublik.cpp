#include "Boublik.h"

#define M_PI 3.14159265358979323846


Boublik::Boublik(int R, int G, int B, int x, int y, int smallRadius, int bigRadius) :Figure(R, G, B, x, y)
{
	this->smallRadius = smallRadius;
	this->bigRadius = bigRadius;
}

Boublik::~Boublik()
{

}

void Boublik::calcParams(float& perimeter, float& area) const
{
	perimeter = 2 * M_PI * this->bigRadius + 2 * M_PI * this->smallRadius;
	area = M_PI * ((this->bigRadius * this->bigRadius) - (this->smallRadius * this->smallRadius));
}

void Boublik::setSizes(int smallRadius, int bigRadius)
{
	this->smallRadius = smallRadius;
	this->bigRadius = bigRadius;
	if (isVisible() == true)
	{
		draw();
	}
}

int Boublik::getSmallRadius() const
{
	return smallRadius;
}

int Boublik::getBigRadius() const
{
	return bigRadius;
}

void Boublik::draw()
{
	cout << " The BOUBLIK draw " << endl;
	cout << " Center (x;y): (" << x << ";" << y << ") " << endl;
	cout << " Outer circle radius: " << bigRadius << endl;
	cout << " Inner circle radius: " << smallRadius << endl;
	cout << " Visible: " << isVisible() << endl;
	cout << " Border color: (" << R << ";" << G << ";" << B << ") " << endl;
	cout << " END " << endl;
	cout << " " << endl;
}

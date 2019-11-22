#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Figure.h"
#include "Boublik.h"
#include "FilledBoublik.h"

using namespace std;

int main() {
	int c, x, y, smallRadius, bigRadius, f;
	c = 455;
	x = 2;
	y = 1;
	smallRadius = 4;
	bigRadius = 47;
	f = 17;
	Boublik* boublik = new Boublik(c, x, y, smallRadius, bigRadius);
	FilledBoublik* filledBoublik = new FilledBoublik(c, x, y, smallRadius, bigRadius, f);
	Figure* figure;
	float perimether, area;

	boublik->setVisible();
	filledBoublik->setVisible();


	cout << " Moving boublik......  " << endl;
	boublik->move(3, 3);
	cout << " Changing boublik parameters......  " << endl;
	boublik->setSizes(7, 30);
	cout << " Getting inner circle radius......  " << endl;
	int k = boublik->getSmallRadius();
	cout << " Inner circle radius:  " << k << endl;
	cout << " " << endl;
	cout << " Getting outer circle radius......  " << endl;
	int m = boublik->getBigRadius();
	cout << " The outer circle radius  " << m << endl;
	cout << " " << endl;


	cout << " Moving filled boublik......  " << endl;
	filledBoublik->move(4, 4);
	cout << " Changing filled boublik parameters......  " << endl;
	filledBoublik->setSizes(17, 45);
	cout << " Getting inner circle radius......  " << endl;
	int o = filledBoublik->getSmallRadius();
	cout << " Inner circle radius: " << o << endl;
	cout << " " << endl;
	cout << " Getting outer circle radius......  " << endl;
	int w = filledBoublik->getBigRadius();
	cout << " The outer circle radius  " << w << endl;
	cout << " " << endl;
	cout << " Change Border Color (filled boublik) " << endl;
	filledBoublik->setBorderColor(347);
	int l = filledBoublik->getBorderColor();
	int p = filledBoublik->getFillColor();
	cout << " Border Color " << l << endl;
	cout << " " << endl;
	cout << " Moving filled boublik... " << endl;
	filledBoublik->move(0, 0);



	figure = boublik;
	cout << " Moving figure (boublik)..." << endl;
	figure->move(2, 3);
	figure->calcParams(perimether, area);
	cout << " P = " << perimether << endl;
	cout << " S = " << area << endl;
	cout << " " << endl;



	figure = filledBoublik;
	cout << " Moving figure (filledBoublik)... " << endl;
	figure->move(3, 4);
	figure->calcParams(perimether, area);
	cout << " P = " << perimether << endl;
	cout << " S = " << area << endl;
	cout << " " << endl;


	delete boublik;
	delete filledBoublik;
	system("pause");
	return 0;
	
}
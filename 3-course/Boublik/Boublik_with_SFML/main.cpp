#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <SFML/Graphics.hpp>
#include<windows.h>

#include "Figure.h"
#include "Boublik.h"
#include "FilledBoublik.h"

using namespace std;
using namespace sf;

int main() 
{
	BorderColor border_color;// ���� ������� (���������)
	FillColor fill_color;// ���� ������� ������ (���������)
	Point center;
	/*int R, G, B; // ���� �������
	int RED, GREEN, BLUE; // ���� ������� ������*/
	int smallRadius, bigRadius;
	border_color.R = 0;  border_color.G = 0;  border_color.B = 0;
	fill_color.RED = 223; fill_color.GREEN = 0; fill_color.BLUE = 0;
	center.x = 0;
	center.y = 0;
	smallRadius = 20;
	bigRadius = 60;

	Boublik* boublik = new Boublik(border_color.R, border_color.G, border_color.B, center.x, center.y, smallRadius, bigRadius);
	FilledBoublik* filledBoublik = new FilledBoublik(border_color.R, border_color.G, border_color.B, center.x, center.y, smallRadius, bigRadius, fill_color.RED, fill_color.GREEN, fill_color.BLUE);
	Figure* figure;
	float perimether, area;

	boublik->setVisible();
	filledBoublik->setVisible();

	//--------------------------<�������>--------------------------------------------------------------------
	// ������������� 8-�� ������� �����������
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	// ������, ������� �������� ������� ����� ����������
	RenderWindow window(VideoMode(1000,1000), "Boublik with SFML", Style::Default, settings);

	// ������� ���� ����������. ����������� ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� ������� � ����� ������� ����
			if (event.type == Event::Closed)
			{
				// ����� ��������� ����
				window.close(); 
			}
		}

		window.clear(Color::White); // ������������� ���� ����
		
		// ������ �����
		Font font; // ��������� �����
		font.loadFromFile("D:\\VS_projects\\SFML_tutorial\\tutorial\\Fonts\\times.ttf"); // ��������� ����� �� �����
		Text text; // ��������� �����
		text.setFont(font); // ������������� ����� �� ���� 
		text.setString("Boublik:"); // ������ ������������ ������
		text.setCharacterSize(24); // ������ ������ ������ � ��������
		text.setFillColor(Color::Black); // ������ ���� ��� ������
		window.draw(text); // ������� ����� � ����

		// ������������� ������
		CircleShape BIGcircle(60.f);
		BIGcircle.setOutlineThickness(2.f); // ������������� ������� ������� �����
		BIGcircle.setOutlineColor(Color(border_color.R, border_color.G, border_color.B)); // ������������� ���� �������
		BIGcircle.setPosition(100, 15); // ���������� ���� ��� ����������� ����������� � ����
		window.draw(BIGcircle); // ��������� �����
		CircleShape SMALLcircle(20.f);
		SMALLcircle.setOutlineThickness(2.f); // ������������� ������� ������� �����
		SMALLcircle.setOutlineColor(Color(border_color.R, border_color.G, border_color.B)); // ������������� ���� �������
		SMALLcircle.setPosition(140, 55); // ���������� ���� ��� ����������� ����������� � ����
		window.draw(SMALLcircle); // ��������� �����



		// ������������� ����������� ������
		text.setString("Filled Boublik:"); // ������ ������������ ������
		//text.setCharacterSize(24); // ������ ������ ������ � ��������
		//text.setFillColor(Color::Black); // ������ ���� ��� ������
		text.setPosition(450, 0);
		window.draw(text); // ������� ����� � ����
		CircleShape filledBIGcircle(60.f);
		filledBIGcircle.setFillColor(Color(fill_color.RED, fill_color.GREEN, fill_color.BLUE)); // ����������� ��� ����
		filledBIGcircle.setOutlineThickness(2.f); // ������������� ������� ������� �����
		filledBIGcircle.setOutlineColor(Color(border_color.R, border_color.G, border_color.B)); // ������������� ���� �������
		filledBIGcircle.setPosition(600, 15); // ���������� ���� ��� ����������� ����������� � ����
		window.draw(filledBIGcircle); // ��������� �����
		CircleShape filledSMALLcircle(20.f);
		filledSMALLcircle.setOutlineThickness(2.f); // ������������� ������� ������� �����
		filledSMALLcircle.setOutlineColor(Color(border_color.R, border_color.G, border_color.B)); // ������������� ���� �������
		filledSMALLcircle.setPosition(640, 55); // ���������� ���� ��� ����������� ����������� � ����
		window.draw(filledSMALLcircle); // ��������� �����
		

		


		window.display(); // ��������� ����
	}


	cout << " Moving boublik......  " << endl;
	boublik->move(3, 3);
	cout << " Changing boublik parameters......  " << endl;
	boublik->setSizes(7, 30);
	cout << " Getting inner circle radius......  " << endl;
	int smallRadius_for_boublik = boublik->getSmallRadius();
	cout << " Inner circle radius:  " << smallRadius_for_boublik << endl;
	cout << " " << endl;
	cout << " Getting outer circle radius......  " << endl;
	int bigRadius_for_boublik = boublik->getBigRadius();
	cout << " The outer circle radius  " << bigRadius_for_boublik << endl;
	cout << " " << endl;
	


	cout << " Moving filled boublik......  " << endl;
	filledBoublik->move(4, 4);
	cout << " Changing filled boublik parameters......  " << endl;
	filledBoublik->setSizes(17, 45);
	cout << " Getting inner circle radius......  " << endl;
	int smallRadius_filled_boublik = filledBoublik->getSmallRadius();
	cout << " Inner circle radius: " << smallRadius_filled_boublik << endl;
	cout << " " << endl;
	cout << " Getting outer circle radius......  " << endl;
	int bigRadius_filled_boublik = filledBoublik->getBigRadius();
	cout << " The outer circle radius  " << bigRadius_filled_boublik << endl;
	cout << " " << endl;
	cout << " Change Border Color (filled boublik) " << endl;
	filledBoublik->setBorderColor(140, 140, 0);
	border_color = filledBoublik->getBorderColor();
	fill_color = filledBoublik->getFillColor();
	cout << " Border color: (" << border_color.R << ";" << border_color.G << ";" << border_color.B << ") " << endl;
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
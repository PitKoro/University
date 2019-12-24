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
	BorderColor border_color;// Цвет контура (структура)
	FillColor fill_color;// Цвет заливки фигуры (структура)
	Point center;
	/*int R, G, B; // Цвет контура
	int RED, GREEN, BLUE; // Цвет заливки фигуры*/
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

	//--------------------------<ГРАФИКА>--------------------------------------------------------------------
	// Устанавливаем 8-ой уровень сглаживания
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Объект, который является главным окном приложения
	RenderWindow window(VideoMode(1000,1000), "Boublik with SFML", Style::Default, settings);

	// Главный цикл приложения. Выполняется пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на крестик и хочет закрыть окно
			if (event.type == Event::Closed)
			{
				// Тогда закрываем окно
				window.close(); 
			}
		}

		window.clear(Color::White); // Устанавливаем цвет фона
		
		// Задаем текст
		Font font; // Объявляем шрифт
		font.loadFromFile("D:\\VS_projects\\SFML_tutorial\\tutorial\\Fonts\\times.ttf"); // Загружаем шрифт из файла
		Text text; // Объявляем текст
		text.setFont(font); // Устанавливаем шрифт на текс 
		text.setString("Boublik:"); // Задаем отображаемую строку
		text.setCharacterSize(24); // Задаем размер шрифта в пикселях
		text.setFillColor(Color::Black); // Задаем цвет для текста
		window.draw(text); // Выводим текст в окно

		// Устанавливаем бублик
		CircleShape BIGcircle(60.f);
		BIGcircle.setOutlineThickness(2.f); // устанавливаем толщину контура круга
		BIGcircle.setOutlineColor(Color(border_color.R, border_color.G, border_color.B)); // устанавливаем цвет контура
		BIGcircle.setPosition(100, 15); // перемещаем круг для корректного отображения в окне
		window.draw(BIGcircle); // отрисовка круга
		CircleShape SMALLcircle(20.f);
		SMALLcircle.setOutlineThickness(2.f); // устанавливаем толщину контура круга
		SMALLcircle.setOutlineColor(Color(border_color.R, border_color.G, border_color.B)); // устанавливаем цвет контура
		SMALLcircle.setPosition(140, 55); // перемещаем круг для корректного отображения в окне
		window.draw(SMALLcircle); // отрисовка круга



		// Устанавливаем закрашенный бублик
		text.setString("Filled Boublik:"); // Задаем отображаемую строку
		//text.setCharacterSize(24); // Задаем размер шрифта в пикселях
		//text.setFillColor(Color::Black); // Задаем цвет для текста
		text.setPosition(450, 0);
		window.draw(text); // Выводим текст в окно
		CircleShape filledBIGcircle(60.f);
		filledBIGcircle.setFillColor(Color(fill_color.RED, fill_color.GREEN, fill_color.BLUE)); // закрашиваем наш круг
		filledBIGcircle.setOutlineThickness(2.f); // устанавливаем толщину контура круга
		filledBIGcircle.setOutlineColor(Color(border_color.R, border_color.G, border_color.B)); // устанавливаем цвет контура
		filledBIGcircle.setPosition(600, 15); // перемещаем круг для корректного отображения в окне
		window.draw(filledBIGcircle); // отрисовка круга
		CircleShape filledSMALLcircle(20.f);
		filledSMALLcircle.setOutlineThickness(2.f); // устанавливаем толщину контура круга
		filledSMALLcircle.setOutlineColor(Color(border_color.R, border_color.G, border_color.B)); // устанавливаем цвет контура
		filledSMALLcircle.setPosition(640, 55); // перемещаем круг для корректного отображения в окне
		window.draw(filledSMALLcircle); // отрисовка круга
		

		


		window.display(); // Отрисовка окна
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
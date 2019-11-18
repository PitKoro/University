#pragma once

#include<iostream>
using namespace std;

struct Point
{
	int x, y;
};

class Figure
{
private:
	int c; // цвет
	bool visible; // Видимость
protected:
	int x, y; // базовая точка
	virtual void draw() = 0;
public:
	Figure(int c, int x, int y);
	virtual ~Figure();
	void move(int dx, int dy); // сместить фигуру на (dx,dy) – только видимую
	virtual void setBorderColor(int c); // установить цвет фигуры – только видимой
	int getBorderColor() const; // получить цвет
	void setVisible(bool isVisible = true); // показать/спрятать фигуру
	bool isVisible() const; // признак видимости
	virtual void calcParams(float& perimeter, float& area) const = 0; // вычислить периметр и площадь фигуры
	// Получаем центральную точку
	Point getCenter();
};

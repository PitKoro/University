#pragma once

#include<iostream>
using namespace std;

struct Point
{
	int x, y;
};

struct BorderColor
{
	int R, G, B;
};

class Figure
{
private:
	bool visible; // Видимость
protected:
	int x, y; // Базовая точка
	int R, G, B; // Цвет контура
	virtual void draw() = 0;
public:
	Figure(int R, int G, int B, int x, int y);
	virtual ~Figure();
	void move(int dx, int dy); // сместить фигуру на (dx,dy) – только видимую
	virtual void setBorderColor(int R, int G, int B); // установить цвет фигуры – только видимой
	void setVisible(bool isVisible = true); // показать/спрятать фигуру
	bool isVisible() const; // признак видимости
	virtual void calcParams(float& perimeter, float& area) const = 0; // вычислить периметр и площадь фигуры
	// Получаем центральную точку
	Point getCenter();
	// Получаем цвет контура
	BorderColor getBorderColor();
};

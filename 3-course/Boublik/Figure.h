#pragma once

#include<iostream>
using namespace std;

struct Point
{
	int x, y;
};

class Figure
{
    int c; // цвет
    bool visible;
protected:
    int x,y; // базовая точка
    virtual void draw() const;
public:
    Figure(int c, int x, int y);
    virtual ~Figure();
    void move(int dx, int dy); // сместить фигуру на (dx,dy) – только видимую
    void setBorderColor(int c); // установить цвет фигуры – только видимой
    int getBorderColor() const; // получить цвет
    void setVisible( bool isVisible = true ); // показать/спрятать фигуру
    bool isVisible() const; // признак видимости
    virtual void calcParams( float& perimeter, float& area ) const; // вычислить периметр и площадь фигуры
    
};
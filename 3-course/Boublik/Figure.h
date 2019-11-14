#pragma once

#include<iostream>
using namespace std;

class Figure
{
    int c; // цвет
    bool visible;
protected:
    int x,y; // базовая точка
    virtual void draw() const;
public:
    Figure(int c, int x, int y);
    ~Figure();
    void move(int dx, int dy); // сместить фигуру на (dx,dy) – только видимую
    void setBorderColor(int c); // установить цвет фигуры – только видимой
    int getBorderColor() const; // получить цвет
    void setVisible( bool isVisible = true ); // показать/спрятать фигуру
    bool isVisible() const; // признак видимости
    virtual void calcParams( float&amp; perimeter, float&amp; area ) const;
    // вычислить периметр и площадь фигуры
};
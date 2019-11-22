#pragma once
#include "Boublik.h"


class FilledBoublik : public Boublik
{
private:
	// Цвет заполнения фигуры.
	int f;
public:
	FilledBoublik(int c, int x, int y, int smallRadius, int bigRadius, int f);
	~FilledBoublik();
	// Изменяет цвет заполнения.
	void setFillColor(int f);
	// Получить цвет заполнения.
	int getFillColor();
	/// Изменение цвет аграницы.
	virtual void setBorderColor(int c);
protected:
	virtual void draw();
};
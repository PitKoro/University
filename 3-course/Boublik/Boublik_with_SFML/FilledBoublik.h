#pragma once
#include "Boublik.h"

struct FillColor
{
	int RED, GREEN, BLUE;
};

class FilledBoublik : public Boublik
{
private:
	// Цвет заполнения фигуры.
	int RED, GREEN, BLUE;
public:
	FilledBoublik(int R, int G, int B, int x, int y, int smallRadius, int bigRadius, int RED, int GREEN, int BLUE);
	~FilledBoublik();
	// Изменяет цвет заполнения.
	void setFillColor(int RED, int GREEN, int BLUE);
	// Получить цвет заполнения.
	FillColor getFillColor();
	/// Изменение цвет аграницы.
	virtual void setBorderColor(int R, int G, int B);
protected:
	virtual void draw();
};
#pragma once

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
#include "Visitor/Visitor.h"

class Rectangle : public Figure {

private:
	int topLeftX;
	int topLeftY;
	int bottomRightX;
	int bottomRightY;

public:
	Rectangle();
	Rectangle(int firstX, int firstY, int secondX, int secondY, QColor color);
	Rectangle(const Rectangle& rectangle) {

		this->topLeftX = rectangle.topLeftX;
		this->topLeftY = rectangle.topLeftY;
		this->bottomRightX = rectangle.bottomRightX;
		this->bottomRightY = rectangle.bottomRightY;
		this->color = rectangle.color;
	}
	Rectangle* Clone() {
		return new Rectangle(*this);
	}
	~Rectangle();
	int gettopLeftX();
	int gettopLeftY();
	int getbottomRightX();
	int getbottomRightY();
	int getWidth();
	int getHeight();
	void settopLeftX(int topLeftX);
	void settopLeftY(int topLeftY);
	void setbottomRightX(int bottomRightX);
	void setbottomRightY(int bottomRightY);
	virtual QString getString();
	void Accept(Visitor *visitor);
};

#endif // RECTANGLE_H

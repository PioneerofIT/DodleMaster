#pragma once

#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Figure.h"
#include "Visitor/Visitor.h"

class Rhombus : public Figure {

private:
	int topLeftX;
	int topLeftY;
	int bottomRightX;
	int bottomRightY;

public:
	Rhombus();
	Rhombus(int firstX, int firstY, int secondX, int secondY, QColor color);
	Rhombus(const Rhombus& rhombus) {

		this->topLeftX = rhombus.topLeftX;
		this->topLeftY = rhombus.topLeftY;
		this->bottomRightX = rhombus.bottomRightX;
		this->bottomRightY = rhombus.bottomRightY;
		this->color = rhombus.color;
	}
	Rhombus* Clone() {
		return new Rhombus(*this);
	}
	~Rhombus();
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

#endif // RHOMBUS_H

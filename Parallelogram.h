#pragma once

#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "Figure.h"
#include "Visitor/Visitor.h"

class Parallelogram : public Figure {

private:
	int topLeftX;
	int topLeftY;
	int bottomRightX;
	int bottomRightY;

public:
	Parallelogram();
	Parallelogram(int firstX, int firstY, int secondX, int secondY, QColor color);
	Parallelogram (const Parallelogram& parallelogram) {

		this->topLeftX = parallelogram.topLeftX;
		this->topLeftY = parallelogram.topLeftY;
		this->bottomRightX = parallelogram.bottomRightX;
		this->bottomRightY = parallelogram.bottomRightY;
		this->color = parallelogram.color;
	}
	Parallelogram* Clone() {
		return new Parallelogram(*this);
	}
	~Parallelogram();
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
	void Parallelogram::Accept(Visitor *visitor);
};

#endif // PARALLELOGRAM_H

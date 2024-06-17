
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Figure.h"
#include "Visitor/Visitor.h"

class Triangle : public Figure {

private:
	int topLeftX;
	int topLeftY;
	int bottomRightX;
	int bottomRightY;

public:
	Triangle();
	Triangle(int firstX, int firstY, int secondX, int secondY, QColor color);
	Triangle(const Triangle& triangle) {

		this->topLeftX = triangle.topLeftX;
		this->topLeftY = triangle.topLeftY;
		this->bottomRightX = triangle.bottomRightX;
		this->bottomRightY = triangle.bottomRightY;
		this->color = triangle.color;
	}
	Triangle* Clone() {
		return new Triangle(*this);
	}
	~Triangle();
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

#endif // TRIANGLE_H


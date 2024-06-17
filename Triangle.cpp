
#include "Triangle.h"
#include <stdlib.h>


Triangle::Triangle() {

}


Triangle::Triangle(int firstX, int firstY, int secondX, int secondY, QColor color) :Figure(color) {

	if (secondX > firstX) {
		this->topLeftX = firstX;
		this->bottomRightX = secondX;
	}
	else {
		this->topLeftX = secondX;
		this->bottomRightX = firstX;
	}
	if (secondY > firstY) {
		this->bottomRightY = secondY;
		this->topLeftY = firstY;
	}
	else {
		this->bottomRightY = firstY;
		this->topLeftY = secondY;
	}
}

int Triangle::gettopLeftX() {
	return this->topLeftX;
}

int Triangle::gettopLeftY() {
	return this->topLeftY;
}

int Triangle::getbottomRightX() {
	return this->bottomRightX;
}

int Triangle::getbottomRightY() {
	return this->bottomRightY;
}

void Triangle::settopLeftX(int topLeftX) {

	this->topLeftX = topLeftX;

}

void Triangle::settopLeftY(int topLeftY) {

	this->topLeftY = topLeftY;

}

void Triangle::setbottomRightX(int bottomRightX) {

	this->bottomRightX = bottomRightX;

}

void Triangle::setbottomRightY(int bottomRightY) {

	this->bottomRightY = bottomRightY;

}
int Triangle::getWidth() {
	return abs(this->topLeftX - this->bottomRightX);
}

int Triangle::getHeight() {
	return abs(this->topLeftY - this->bottomRightY);
}

QString Triangle::getString() {
	auto data = QString("%1 %2 %3 %4 %5 %6 %7 %8 \n").arg(5).arg(gettopLeftX()).arg(gettopLeftY()).arg(getbottomRightX()).arg(getbottomRightY()).arg(getcolor().red()).arg(getcolor().green()).arg(getcolor().blue());
	return data;
}

void Triangle::Accept(Visitor *visitor) {
	visitor->Visit(this);
}


Triangle::~Triangle() {

}

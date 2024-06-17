
#include "Rhombus.h"
#include <stdlib.h>


Rhombus::Rhombus() {

}


Rhombus::Rhombus(int firstX, int firstY, int secondX, int secondY, QColor color) :Figure(color) {

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

int Rhombus::gettopLeftX() {
	return this->topLeftX;
}

int Rhombus::gettopLeftY() {
	return this->topLeftY;
}

int Rhombus::getbottomRightX() {
	return this->bottomRightX;
}

int Rhombus::getbottomRightY() {
	return this->bottomRightY;
}

void Rhombus::settopLeftX(int topLeftX) {

	this->topLeftX = topLeftX;

}

void Rhombus::settopLeftY(int topLeftY) {

	this->topLeftY = topLeftY;

}

void Rhombus::setbottomRightX(int bottomRightX) {

	this->bottomRightX = bottomRightX;

}

void Rhombus::setbottomRightY(int bottomRightY) {

	this->bottomRightY = bottomRightY;

}

int Rhombus::getWidth() {
	return abs(this->topLeftX - this->bottomRightX);
}

int Rhombus::getHeight() {
	return abs(this->topLeftY - this->bottomRightY);
}

QString Rhombus::getString() {
	auto data = QString("%1 %2 %3 %4 %5 %6 %7 %8 \n").arg(6).arg(gettopLeftX()).arg(gettopLeftY()).arg(getbottomRightX()).arg(getbottomRightY()).arg(getcolor().red()).arg(getcolor().green()).arg(getcolor().blue());
	return data;
}

void Rhombus::Accept(Visitor *visitor) {
	visitor->Visit(this);
}

Rhombus::~Rhombus() {

}

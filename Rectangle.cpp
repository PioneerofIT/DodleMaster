
#include "Rectangle.h"
#include <stdlib.h>


Rectangle::Rectangle() {

}


Rectangle::Rectangle(int firstX, int firstY, int secondX, int secondY, QColor color) :Figure(color) {

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

int Rectangle::gettopLeftX() {
	return this->topLeftX;
}

int Rectangle::gettopLeftY() {
	return this->topLeftY;
}

int Rectangle::getbottomRightX() {
	return this->bottomRightX;
}

int Rectangle::getbottomRightY() {
	return this->bottomRightY;
}

void Rectangle::settopLeftX(int topLeftX) {

	this->topLeftX = topLeftX;

}

void Rectangle::settopLeftY(int topLeftY) {

	this->topLeftY = topLeftY;

}

void Rectangle::setbottomRightX(int bottomRightX) {

	this->bottomRightX = bottomRightX;

}

void Rectangle::setbottomRightY(int bottomRightY) {

	this->bottomRightY = bottomRightY;

}

int Rectangle::getWidth() {
	return abs(this->topLeftX - this->bottomRightX);
}

int Rectangle::getHeight() {
	return abs(this->topLeftY - this->bottomRightY);
}

QString Rectangle::getString() {
	auto data = QString("%1 %2 %3 %4 %5 %6 %7 %8 \n").arg(4).arg(gettopLeftX()).arg(gettopLeftY()).arg(getbottomRightX()).arg(getbottomRightY()).arg(getcolor().red()).arg(getcolor().green()).arg(getcolor().blue());
	return data;
}

void Rectangle::Accept(Visitor *visitor) {
	visitor->Visit(this);
}

Rectangle::~Rectangle() {

}

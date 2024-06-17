
#include "Parallelogram.h"
#include <stdlib.h>


Parallelogram::Parallelogram() {

}


Parallelogram::Parallelogram(int firstX, int firstY, int secondX, int secondY, QColor color) :Figure(color) {

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

int Parallelogram::gettopLeftX() {
	return this->topLeftX;
}

int Parallelogram::gettopLeftY() {
	return this->topLeftY;
}

int Parallelogram::getbottomRightX() {
	return this->bottomRightX;
}

int Parallelogram::getbottomRightY() {
	return this->bottomRightY;
}

void Parallelogram::settopLeftX(int topLeftX) {

	this->topLeftX = topLeftX;

}

void Parallelogram::settopLeftY(int topLeftY) {

	this->topLeftY = topLeftY;

}

void Parallelogram::setbottomRightX(int bottomRightX) {

	this->bottomRightX = bottomRightX;

}

void Parallelogram::setbottomRightY(int bottomRightY) {

	this->bottomRightY = bottomRightY;

}


int Parallelogram::getWidth() {
	return abs(this->topLeftX - this->bottomRightX);
}

int Parallelogram::getHeight() {
	return abs(this->topLeftY - this->bottomRightY);
}

QString Parallelogram::getString() {
	auto data = QString("%1 %2 %3 %4 %5 %6 %7 %8 \n").arg(7).arg(gettopLeftX()).arg(gettopLeftY()).arg(getbottomRightX()).arg(getbottomRightY()).arg(getcolor().red()).arg(getcolor().green()).arg(getcolor().blue());
	return data;
}

void Parallelogram::Accept(Visitor *visitor) {
	visitor->Visit(this);
}

Parallelogram::~Parallelogram() {

}

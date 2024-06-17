
#include "Line.h"

Line::Line() {

}


Line::Line(int startX, int startY, int endX, int endY, QColor color) :Figure(color) {

	this->startX = startX;
	this->startY = startY;
	this->endX = endX;
	this->endY = endY;

}

int Line::getStartX() {
	return this->startX;
}

int Line::getStartY() {
	return this->startY;
}

int Line::getEndX() {
	return this->endX;
}

int Line::getEndY() {
	return this->endY;
}

void Line::setStartX(int startX) {
	this->startX = startX;
}

void Line::setStartY(int startY) {
	this->startY = startY;
}

void Line::setEndX(int endX) {
	this->endX = endX;

}

void Line::setEndY(int endY) {
	this->endY = endY;

}


QString Line::getString() {
	auto data = QString("%1 %2 %3 %4 %5 %6 %7 %8 \n").arg(1).arg(getStartX()).arg(getStartY()).arg(getEndX()).arg(getEndY()).arg(getcolor().red()).arg(getcolor().green()).arg(getcolor().blue());
	return data;
}

void Line::Accept(Visitor *visitor) {
	visitor->Visit(this);
}

Line::~Line() {

}

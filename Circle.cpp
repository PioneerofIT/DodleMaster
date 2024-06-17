#include "Circle.h"



Circle::Circle(int centerX, int centerY, int radius, QColor color) : Figure(color)
{
	this->centerX = centerX;
	this->centerY = centerY;
	this->radius = radius;
}

int Circle::getCenterX()
{
	return this->centerX;
}

int Circle::getCenterY()
{
	return this->centerY;
}

void Circle::setCenterX(int centerX)
{
	this->centerX = centerX;
}

void Circle::setCenterY(int centerY)
{
	this->centerY = centerY;
}

int Circle::getRadius() {
	return this->radius;
}

QString Circle::getString()
{
	auto data = QString("%1 %2 %3 %4 %5 %6 %7 \n").arg(2).arg(getCenterX()).arg(getCenterY()).arg(getRadius()).arg(getcolor().red()).arg(getcolor().green()).arg(getcolor().blue());
	return data;
}

/* Visist Class -> virtual void Visit(Circle *circle) = 0; È£Ãâ*/
void Circle::Accept(Visitor *visitor)
{
	visitor->Visit(this);
}

Circle::~Circle()
{

}





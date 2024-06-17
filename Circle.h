
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"
#include "Visitor/Visitor.h"

class Circle : public Figure
{

private:
	int centerX; //ÁßÁ¡ XÁÂÇ¥
	int centerY; //ÁßÁ¡ YÁÂÇ¥
	int radius; //¹ÝÁö¸§

public:
	Circle(int centerX, int centerY, int radius, QColor color); //color´Â QColorÀÇ ¸â¹ö
	~Circle();
	Circle(const Circle& circle)
	{
		
		this->centerX = circle.centerX;
		this->centerY = circle.centerY;
		this->radius = circle.radius;
		this->color = circle.color;

	}
	//
	Circle* Clone()
	{
		return new Circle(*this);
	}

	int getCenterX();
	int getCenterY();
	int getRadius();

	virtual QString getString();

	void setMovePos(int disX, int disY)
	{
		this->centerX = this->centerX + disX;
		this->centerY = this->centerY + disY;
		
	}
	void setCenterX(int centerX);
	void setCenterY(int centerY);

	void Accept(Visitor *visitor);

};

#endif // CIRCLE_H

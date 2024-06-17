
#ifndef FIGURE_H
#define FIGURE_H

#include <QtWidgets/QMainWindow>
#include <QCoreApplication>
#include <QColor>
#include "Visitor/Visitor.h"

class Figure
{

public:

	Figure();
	Figure(QColor color);
	Figure(const Figure& figure) {}
	virtual Figure* Clone() = 0;
	virtual ~Figure() = 0;
	virtual void Accept(Visitor *visitor) = 0;
	virtual QString getString() = 0;
	
protected:
	QColor color;

public:
	QColor getcolor() { return this->color; }
};

#endif // FIGURE_H

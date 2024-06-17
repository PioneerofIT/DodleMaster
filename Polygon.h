#pragma once

#ifndef POLYGON_H
#define POLYGON_H
#include <QList>
#include "Figure.h"
#include "Visitor/Visitor.h"
#include <qdebug.h>

class Polygon : public Figure {

private:
	QList<QPoint> points;
	QPoint p;

public:
	Polygon(QList<QPoint> points, QColor color);
	Polygon(const Polygon& polygon) {

		this->points = polygon.points;
		this->color = polygon.color;
	}
	Polygon* Clone() {
		return new Polygon(*this);
	}
	~Polygon();
	QList<QPoint> getPoints();
	virtual QString getString();
	void setPoint(int i, int disX, int disY);
	QPoint getPoint(int point);
	int squareNum();

	void setMovePos(int disX, int disY) {

		for (int i = 0; i < points.size(); i++) {
			
			int x = points.at(i).x() + disX;
			int y = points.at(i).y() + disY;
			
			points.removeAt(i);
			
			QPoint point;
			point.setX(x);
			point.setY(y);

			points.insert(i, point);
		
		}

	}


	void Accept(Visitor *visitor);
};

#endif // CIRCLE_H

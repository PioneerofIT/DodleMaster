
#include "Polygon.h"



Polygon::Polygon(QList<QPoint> points, QColor color) : Figure(color) {
	this->points = points;
}

QList<QPoint> Polygon::getPoints() {
	return this->points;
}

QString Polygon::getString() {
	QList<QPoint> points = getPoints();
	auto data = QString("%1 %2 %3 %4 %5").arg(3).arg(getcolor().red()).arg(getcolor().green()).arg(getcolor().blue()).arg(points.size());
	
	for (int i = 0; i < points.size(); i++) {
		data.append(QString(" %1 %2").arg(points.at(i).x()).arg(points.at(i).y()));
	}
	data.append("\n");
	return data + "";
	
}


void Polygon::setPoint(int i, int x, int y) {
	
	const QPoint &point = this->points.at(i);
	const_cast<QPoint&>(point).setX(x);
	const_cast<QPoint&>(point).setY(y);
	
}

QPoint Polygon::getPoint(int point) {
	
	return this->points.at(point);

}

int Polygon::squareNum() {

	return this->points.size();
}


void Polygon::Accept(Visitor *visitor) {
	visitor->Visit(this);
}

Polygon::~Polygon() {

}





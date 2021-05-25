#include "Line.h"

Line::Line()
{

}

Line::Line(const Point& a, const Point& b)
{
	pointA = a;
	pointB = b;
	vectorAB = Vector(a, b);
}

Line::Line(const Vector& v, const Point& a)
{
	pointA = a;
	vectorAB = v;

	pointB = Point((v.getX() + a.getX()), (v.getY() + a.getY()), (v.getX() + a.getY()));
}

Vector Line::lineDirection()
{
	return vectorAB.posokaVector();
}

Vector Line::findNormalVector()
{
	if (getVectorAB().getZ() < getVectorAB().getX()) 
	{
		return Vector(getVectorAB().getY(), -(getVectorAB().getX()), 0);
	}
	else 
	{
		return Vector(0, -(getVectorAB().getZ()), getVectorAB().getY());
	}
}

int Line::angleTwoLines(Line& l)
{
	double x1 = vectorAB.getX();
	double y1 = vectorAB.getY();
	double z1 = vectorAB.getZ();

	double x2 = l.getVectorAB().getX();
	double y2 = l.getVectorAB().getY();
	double z2 = l.getVectorAB().getZ();

	double cos_angle = ((x1 * x2) + (y1 * y2) + (z1 * z2)) / (sqrt(pow(x1, 2) + pow(y1, 2) + pow(z1, 2)) * sqrt(pow(x2, 2) + pow(y2, 2) + pow(z2, 2)));
	return(acos(cos_angle) * 180. / 3.14);
}

Point Line::getPointA() const {
	return pointA;
}
Point Line::getPointB() const {
	return pointB;
}
Vector Line::getVectorAB() const {
	return vectorAB;
}

bool Line::operator||(Line& line)
{
	return getVectorAB().paralelVector(line.getVectorAB());
	//return ((vectorAB.getX() / line.vectorAB.getX()) == (vectorAB.getY() / line.vectorAB.getY()) == (vectorAB.getZ() == line.vectorAB.getZ()));

}

bool Line::operator+(const Point& p)
{
	return (this->getPointA().findDistanceToPoint(p) + this->getPointB().findDistanceToPoint(p) == this->getPointA().findDistanceToPoint(this->getPointB()));
}

bool Line::operator==(const Line& l)
{
	if (
		(this->getPointA() == l.getPointA()) &&
		(this->getPointB() == l.getPointB()) &&
		(this->getVectorAB().getX() == l.getVectorAB().getX()) &&
		(this->getVectorAB().getY() == l.getVectorAB().getY()) &&
		(this->getVectorAB().getY() == l.getVectorAB().getY())
		) {
		return true;
	}
	return false;
}

bool Line::operator&&(const Line& l)
{
	if (
		(this->getX() == l.getX()) ||
		(this->getY() == l.getY()) ||
		(this->getZ() == l.getZ())
		) {
		return true;
	}
	return false;
}

bool Line::operator!=(const Line& l)
{
	double x1 = pointA.getX(), y1 = pointA.getY(), z1 = pointA.getZ();

	double x2 = l.pointB.getX(), y2 = l.pointB.getY(), z2 = l.pointB.getZ();

	double Vec_x1 = vectorAB.getX(), Vec_y1 = vectorAB.getY(),Vec_z1 = vectorAB.getZ();

	double  Vec_x2 = l.vectorAB.getX(), Vec_y2 = l.vectorAB.getY(), Vec_z2 = l.vectorAB.getZ();

	double d = 
				(x2 - x1) * ((Vec_y1 * Vec_z2) - (Vec_z1 * Vec_y2)) - 
				(y2 - y1) * ((Vec_x1 * Vec_z2) - (Vec_z1 * Vec_x2)) + 
				(z2 - z1) * ((Vec_x1 * Vec_y2) - (Vec_z1 * Vec_x2));

	if (d != 0)
		return true;

	return false;
}

bool Line::operator|(const Line& l)
{
	if ((vectorAB.getX() * l.vectorAB.getX()) + (vectorAB.getY() * l.vectorAB.getY()) + (vectorAB.getZ() * l.vectorAB.getZ()) == 0) {
		return true;
	}
	return false;
}



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
	return Vector();
}

int Line::angleTwoLines(Line& l)
{
	double x1 = vectorAB.getX();
	double y1 = vectorAB.getY();
	double z1 = vectorAB.getZ();

	double x2 = l.getVectorAB().getX();
	double y2 = l.getVectorAB().getY();
	double z2 = l.getVectorAB().getZ();

	if ((x1 == x2) || (y1 == y2) || (z1 == z2)) {
		double cos_angle = ((x1 * x2) + (y1 * y2) + (z1 * z2)) / (sqrt(pow(x1, 2) + pow(y1, 2) + pow(z1, 2)) * sqrt(pow(x2, 2) + pow(y2, 2) + pow(z2, 2)));
	
		return (acos(cos_angle) * 180. / 3.14);
	}
	else {
		std::cout << "Cannot calculate angle of the two lines\n";
	}
}

Point Line::getPointA() {
	return pointA;
}
Point Line::getPointB() {
	return pointB;
}
Vector Line::getVectorAB() {
	return vectorAB;
}

bool Line::operator||(const Line& line)
{
	return ((vectorAB.getX() / line.vectorAB.getX()) == (vectorAB.getY() / line.vectorAB.getY()) == (vectorAB.getZ() == line.vectorAB.getZ()));

}

bool Line::operator+(const Point& p)
{
	return 0;
}

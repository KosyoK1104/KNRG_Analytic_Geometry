#include "Triangle.h"
//???????? ??????????? (default constructor)
Triangle::Triangle() : a(0), b(0), c(0)
{
	x = Point(0, 0, 0);
    y = Point(0, 0, 0);
    z = Point(0, 0, 0);
}
//?????????? (destructor)
Triangle::~Triangle() {}
//??????????? ? ????????? (constructor with parameters)
Triangle::Triangle(Point& a, Point& b, Point& c) {
	
	x = a;
	y = b;
	z = c;

	this->a = y.findDistanceToPoint(z);
	this->b = x.findDistanceToPoint(z);
	this->c = x.findDistanceToPoint(y);
}
//???? ??????????? (copy constructor)
Triangle::Triangle(const Triangle& rhs)

	: x(rhs.x), y(rhs.y), z(rhs.z), a(rhs.a), b(rhs.b), c(rhs.c)

{}
//get ?????? (get methods)
double Triangle::getA() const
{
	return a;
}

double Triangle::getB() const
{
	return b;
}

double Triangle::getC() const
{
	return c;
}

Point Triangle::getX() const
{
	return x;
}

Point Triangle::getY() const
{
	return y;
}

Point Triangle::getZ() const
{
	return z;
}
//??????? ?? ???????? ?? ???? ?? ?????????? ?? ?????? (function for finding the type of a triangle by sides)
void Triangle::findTriangleKindS() const
{
	if (a == b == c)
	{
		std::cout << "The triangle is equilateral" << std::endl;
	}

	else if (a == b || a == c || b == c)
	{
		std::cout << "The triangle is isosceles" << std::endl;
	}

	else {
		std::cout << "The triangle is scalene" << std::endl;

	}
}
//??????? ?? ???????? ?? ???? ?? ?????????? ?? ???? (function for finding the type of the triangle by angles)
void Triangle::findTriangleKindA() const 
{
	const double Angle = pow(a, 2) + pow(b, 2);

	if (Angle > pow(c, 2))
	{
		std::cout << "The triangle is acute" << std::endl;
	}
	else if (Angle < pow(c, 2))
	{
		std::cout << "The triangle is obtuse" << std::endl;
	}
	else {
		std::cout << "The triangle is right" << std::endl;
	}
}
//??????? ?? ???????? ?? ???????? ?? ?????????? (function for finding the parameter of a triangle)
double Triangle::findTrianglePerimeter() const
{
	double Perimeter;
	Perimeter = a + b + c;
	return Perimeter;
}
//??????? ?? ???????? ?? ???? ?? ?????????? (function for finding the surface of a triangle)
double Triangle::findTriangleSurface() const
{



	double Surface, semiPerimeter;
	semiPerimeter = (a + b + c) / 2;
	Surface = sqrt((semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c)));

	return Surface;
}
//??????? ?? ???????? ?? ?????????? ?? ??????????? (function for finding the medicenter of a triangle)
Point Triangle::findTriangleMedicenter() const
{
	double mx;
	mx = (this->x.getX() + this->y.getX() + this->z.getX()) / 3.0;
	double my;
	my = (this->x.getY() + this->y.getY() + this->z.getY()) / 3.0;
	double mz;
	mz = (this->x.getZ() + this->y.getZ() + this->z.getZ()) / 3.0;

	Point mediCenter = Point(mx, my, mz);

	return mediCenter;

}
//????????????? ?? ???????? < (redefining of < operator)
bool Triangle::operator<(Point& rhs)
{
	Triangle P1(x, rhs, y);
	Triangle P2(y, rhs, z);
	Triangle P3(z, rhs, x);

	return this->findTriangleSurface() == P1.findTriangleSurface() + P2.findTriangleSurface() + P3.findTriangleSurface();
}
//????????????? ?? ???????? > (redefining of > operator)
bool Triangle::operator>(Point& rhs)
{
	/*
	
	x = rhs
	1 = this->x
	2 = this->y
	3 = this->z

	|x-x1	y-y1	z-z1
	|x2-x1	y2-y1	z2-z1
	|x3-x1	y3-y1	z3-z1
	
	*/

	bool inPlane = 
		(rhs.getX() - x.getX()) * (y.getY() - x.getY()) * (z.getZ() - x.getZ()) +
		(rhs.getY() - x.getY()) * (y.getZ() - x.getZ()) * (z.getX() - x.getX()) +
		(rhs.getZ() - x.getZ()) * (y.getX() - x.getX()) * (z.getY() - x.getY()) -
		(rhs.getZ() - x.getZ()) * (y.getY() - x.getY()) * (z.getX() - x.getX()) -
		(rhs.getY() - x.getY()) * (y.getX() - x.getX()) * (z.getZ() - x.getZ()) -
		(rhs.getX() - x.getX()) * (y.getZ() - x.getZ()) * (z.getY() - x.getY()) == 0;

	return inPlane && *this < rhs;
}
//????????????? ?? ???????? == (redefining of == operator)
bool Triangle::operator==(Point& rhs)
{
	bool apb, apc, bpc;

	apb = x.findDistanceToPoint(rhs) + y.findDistanceToPoint(rhs) == x.findDistanceToPoint(y);
	apc = x.findDistanceToPoint(rhs) + z.findDistanceToPoint(rhs) == x.findDistanceToPoint(z);
	bpc = z.findDistanceToPoint(rhs) + y.findDistanceToPoint(rhs) == z.findDistanceToPoint(y);

	return apb || apc || bpc;
}

//?????????? ?? ???????? (defining of an inserter)
std::ostream& Triangle::ins(std::ostream& out)const {
	return out << "\n The triangle has the following sides:\na: " << a << "\nb: " << b << "\nc: " << c << std::endl;
}




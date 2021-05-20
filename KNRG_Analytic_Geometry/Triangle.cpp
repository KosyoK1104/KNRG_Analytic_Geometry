#include "Triangle.h"
Triangle::~Triangle() {}


Triangle::Triangle() : a(0), b(0), c(0)
{
	x = Point(0, 0, 0);
    y = Point(0, 0, 0);
    z = Point(0, 0, 0);
}

Triangle::~Triangle() {

	std::cout << "Destructed" << std::endl;

}
Triangle::Triangle(Point& a, Point& b, Point& c) {

	x = a;
	y = b;
	z = c;

	this->a = y.findDistanceToPoint(z);
	this->b = x.findDistanceToPoint(z);
	this->c = x.findDistanceToPoint(y);
}

Triangle::Triangle(const Triangle& rhs)

	: x(rhs.x), y(rhs.y), z(rhs.z), a(rhs.a), b(rhs.b), c(rhs.c)

{}

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
double Triangle::findTrianglePerimeter() const
{
	double Perimeter;
	Perimeter = a + b + c;
	return Perimeter;
}
double Triangle::findTriangleSurface() const
{
	double Surface, semiPerimeter;
	semiPerimeter = (a + b + c) / 2;
	Surface = sqrt((semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c)));

	return Surface;
}

Point& Triangle::findTriangleMedicenter() const
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



std::ostream& Triangle::ins(std::ostream& out)const {
	return out << "\n The triangle has the following sides:\na: " << a << "\nb: " << b << "\nc: " << c << std::endl;
}




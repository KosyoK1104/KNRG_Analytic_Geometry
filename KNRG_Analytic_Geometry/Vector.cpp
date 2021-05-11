#include "Vector.h"
Vector::Vector() : Point() {}
Vector::Vector(double x, double y, double z) {
	setX(x);
	setY(y);
	setZ(z);
}
Vector::Vector(const Point& A, const Point& B)
{
	Vector(B.getX() - A.getX(), B.getY() - A.getY(), B.getZ() - A.getZ());
}
Vector::Vector(const Vector& rhs) 
{
	Vector(rhs.getX(), rhs.getY(), rhs.getZ());
}
Vector& Vector::operator=(const Vector& rhs)
{
	if (this != &rhs) {
		Point::operator=(rhs);
	}
	return *this;
}
Vector::~Vector() {
}
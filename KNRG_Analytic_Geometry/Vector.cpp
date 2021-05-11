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
//zadacha 2
double Vector::dulzhinaVector()
{
	return (sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2) == 0));
}
Vector Vector::posokaVector() 
{
double x = getX();
double y = getY();
double z = getZ();
double dulzh = dulzhinaVector();
double i, j, k;
i = x / dulzh;
j = y / dulzh;
k = z / dulzh;
return Vector(i, j, k);
}

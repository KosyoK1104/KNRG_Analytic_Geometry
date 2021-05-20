#include "Vector.h"
Vector::Vector(){}
Vector::Vector(double x, double y, double z) {
	setX(x);
	setY(y);
	setZ(z);
	cout << "v const\n";
}
Vector::Vector(const Point& A, const Point& B)
{
	setX(B.getX() - A.getX());
	//cout << B.getX() - A.getX() << endl;
	setY(B.getY() - A.getY());
	//cout << B.getY() - A.getY() << endl;
	setZ(B.getZ() - A.getZ());
	//cout << B.getZ() - A.getZ() << endl;
	//Vector tmp(B.getX() - A.getX(), B.getY() - A.getY(), B.getZ() - A.getZ());
	cout << "Vector constructed\n";
}
Vector::Vector(const Vector& rhs) 
{
	Vector tmp(rhs.getX(), rhs.getY(), rhs.getZ());
}
Vector& Vector::operator=(const Vector& rhs)
{
	if (this != &rhs) {
		Point::operator=(rhs);
	}
	return *this;
}
Vector::~Vector() {
	cout << "v desc\n";
}
//zadacha 2
double Vector::dulzhinaVector()
{
	//cout << sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
	return sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
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
bool Vector::zeroVector() {
	return (getX() == 0 && getY() == 0 && getZ() == 0);
}
bool Vector::paralelVector(Vector& v) {
	if (this->getX() / v.getX() == this->getY() && this->getY() / v.getY() == this->getZ() / v.getZ()) {
		cout << "Vectors are parallel" << endl;
		return true;
	}
	else {
		cout << "Vectors are not parallel" << endl;
		return false;
	}
}

bool Vector::perpendicularVector(Vector& v) {
	if (this->getX() * v.getX() + this->getY() * v.getY() + this->getZ() * getZ() == 0) {
		cout << "Vectors are perpendicular" << endl;
		return true;
	}
	else {
		cout << "Vectors are not perpendicular" << endl;
		return false;
	}
}
//zadacha 3
Vector Vector::operator+(const Vector& rhs) {
	cout << "Result after addition is new vector: " << endl;
	return Vector(getX() + rhs.getX(), getY() + rhs.getY(), getZ() + rhs.getZ());
}

Vector Vector::operator-(const Vector& rhs) {
	cout << "Result after substraction is new vector: " << endl;
	return Vector(getX() - rhs.getX(), getY() - rhs.getY(), getZ() - rhs.getZ());
}

double Vector::operator*(const Vector& rhs) {
	std::cout << "The result after scalar multiplication is a real number with value ";
	return getX() * rhs.getX() + getY() * rhs.getY() + getZ() * rhs.getZ();
}

Vector Vector::operator*(const double a) {
	std::cout << "The result after multiplication is a new vector with coordinates ";
	return Vector(getX() * a, getY() * a, getZ() * a);
}

double Vector::operator()(const Vector& v2, const Vector& v3) {
	cout << "Result after multiplication: " << endl;
	return (this->getY() * v2.getZ() - v2.getY() * this->getZ()) * v3.getX() - (this->getX() * v2.getZ() - v2.getX() * this->getZ()) * v3.getY() + (this->getX() * v2.getY() - this->getY() * v2.getX()) * v3.getZ();
}

ostream& Vector::ins(ostream& out)const {
	return out /*<< "Vector is with coordinates: "*/ << endl << "X=" << getX() << endl << "Y=" << getY() << endl << "Z=" << getZ() << endl;
}

istream& Vector::ext(istream& in){
	return in;
} 
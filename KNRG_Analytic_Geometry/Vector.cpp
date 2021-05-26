#include "Vector.h"
//дифолтен конструктор
Vector::Vector(){}
//конструктор с параметри
Vector::Vector(double x, double y, double z) {
	setX(x);
	setY(y);
	setZ(z);
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
//копи конструктор
Vector::Vector(const Vector& rhs) 
{
	Vector tmp(rhs.getX(), rhs.getY(), rhs.getZ());
}
//предефиниране на оператор =
Vector& Vector::operator=(const Vector& rhs)
{
	if (this != &rhs) {
		Point::operator=(rhs);
	}
	return *this;
}
//деструктор
Vector::~Vector() {
	cout << "v desc\n";
}
//задача 2
//функция за намиране на дължина на вектор
double Vector::dulzhinaVector()
{
	//cout << sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
	return sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
}
//функция за намиране на посока на вектор
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
//функция за намиране дали векторът е нулев
bool Vector::zeroVector() {
	return (getX() == 0 && getY() == 0 && getZ() == 0);
}
//функция за намиране дали векторът е успореден спрямо друг вектор
bool Vector::paralelVector(const Vector& v) 
{
	if (this->getX() / v.getX() == this->getY() && this->getY() / v.getY() == this->getZ() / v.getZ()) 
	{
		return true;
	}
	else {
		return false;
	}
}
//функция за намиране дали векторът е перпендикулярен на друг вектор
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
//задача 3
//предефиниране на оператор +
Vector Vector::operator+(const Vector& rhs) {
	cout << "Result after addition is new vector with coordinates: " << endl;
	return Vector(getX() + rhs.getX(), getY() + rhs.getY(), getZ() + rhs.getZ());
}
//предефиниране на оператор -
Vector Vector::operator-(const Vector& rhs) {
	cout << "Result after substraction is new vector: " << endl;
	return Vector(getX() - rhs.getX(), getY() - rhs.getY(), getZ() - rhs.getZ());
}
//предефиниране на оператор ^
Vector Vector::operator^(const Vector& v) {
	cout << "Result after vector multiplication of two vectors is new vector: " << endl;
	return Vector(getX() * v.getX(), getY() * v.getY(), getZ() * v.getZ());
}
//предефиниране на оператор * (за умножение на вектор с друг вектор)
double Vector::operator*(const Vector& rhs) {
	std::cout << "The result after multiplication is a real number with value ";
	return getX() * rhs.getX() + getY() * rhs.getY() + getZ() * rhs.getZ();
}
//предефиниране на оператор * (за умножение на вектор с реално число)
Vector Vector::operator*(const double a) {
	std::cout << "The result after multiplication is a new vector with coordinates ";
	return Vector(getX() * a, getY() * a, getZ() * a);
}
//предефиниране на оператор() (за умножение на 3 вектора)
double Vector::operator()(const Vector& v2, const Vector& v3) {
	cout << "Result after multiplication: " << endl;
	return (this->getY() * v2.getZ() - v2.getY() * this->getZ()) * v3.getX() - (this->getX() * v2.getZ() - v2.getX() * this->getZ()) * v3.getY() + (this->getX() * v2.getY() - this->getY() * v2.getX()) * v3.getZ();
}
//принтиране на вектор
ostream& Vector::ins(ostream& out)const {
	return out /*<< "Vector is with coordinates: "*/ << endl << "X=" << getX() << endl << "Y=" << getY() << endl << "Z=" << getZ() << endl;
}
//въвеждане на вектор
istream& Vector::ext(istream& in){
	return in;
} 
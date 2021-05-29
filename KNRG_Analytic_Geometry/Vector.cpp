#include "Vector.h"
//дифолтен конструктор (default constructor)
Vector::Vector(){}
//конструктор с параметри (constructor with parameters)
Vector::Vector(double x, double y, double z) {
	setX(x);
	setY(y);
	setZ(z);
}
Vector::Vector(const Point& A, const Point& B)
{
	setX(B.getX() - A.getX());
	setY(B.getY() - A.getY());
	setZ(B.getZ() - A.getZ());
}
//копи конструктор (copy constructor) 
Vector::Vector(const Vector& rhs) 
{
	Vector tmp(rhs.getX(), rhs.getY(), rhs.getZ());
}
//предефиниране на оператор = (redefining of = operator)
Vector& Vector::operator=(const Vector& rhs)
{
	if (this != &rhs) {
		Point::operator=(rhs);
	}
	return *this;
}
//деструктор (destructor)
Vector::~Vector() {}
//задача 2 (task 2)
//функция за намиране на дължина на вектор (function for finding the lenght of a vector)
double Vector::dulzhinaVector()
{
	//cout << sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
	return sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
}
//функция за намиране на посока на вектор (function of finding the direction of a vector)
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
//функция за намиране дали векторът е нулев (function for finding if vector is null)
bool Vector::zeroVector() {
	return (getX() == 0 && getY() == 0 && getZ() == 0);
}
//функция за намиране дали векторът е успореден спрямо друг вектор (function for finding if cector is parallel for other vector)
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
//функция за намиране дали векторът е перпендикулярен на друг вектор (function for finding if vector is perpendicular to other vector)
bool Vector::perpendicularVector(Vector& v) {
	if (this->getX() * v.getX() + this->getY() * v.getY() + this->getZ() * getZ() == 0) {
		
		return true;
	}
	else {
		
		return false;
	}
}
//задача 3 (task 3)
//предефиниране на оператор + [събиране на два вектора] (redefining of + operator [additon of two vectors])
Vector Vector::operator+(const Vector& rhs) {

	return Vector(getX() + rhs.getX(), getY() + rhs.getY(), getZ() + rhs.getZ());
}
//предефиниране на оператор - [изваждане на два вектора] (redefining of - operator [substraction of two vectors])
Vector Vector::operator-(const Vector& rhs) {

	return Vector(getX() - rhs.getX(), getY() - rhs.getY(), getZ() - rhs.getZ());
}
//предефиниране на оператор ^ [векторно произведение на два вектора](redefining of ^ operator [vector multiplication of two vectors])
Vector Vector::operator^(const Vector& v) {

	return Vector(getX() * v.getX(), getY() * v.getY(), getZ() * v.getZ());
}
//предефиниране на оператор * [за умножение на вектор с друг вектор] (redefining of * operator [for multiplication of a vector with another vector]) 
double Vector::operator*(const Vector& rhs) {

	return getX() * rhs.getX() + getY() * rhs.getY() + getZ() * rhs.getZ();
}
//предефиниране на оператор * [за умножение на вектор с реално число] (redefining of * operator [for multiplication of a vector with a real number])
Vector Vector::operator*(const double a) {

	return Vector(getX() * a, getY() * a, getZ() * a);
}
//предефиниране на оператор() [за умножение на 3 вектора] (redefining of () operator [for multiplication of 3 vectors])
double Vector::operator()(const Vector& v2, const Vector& v3) {

	return (this->getY() * v2.getZ() - v2.getY() * this->getZ()) * v3.getX() - (this->getX() * v2.getZ() - v2.getX() * this->getZ()) * v3.getY() + (this->getX() * v2.getY() - this->getY() * v2.getX()) * v3.getZ();
}
//принтиране на вектор (printing a vector)
ostream& Vector::ins(ostream& out)const {
	return out /*<< "Vector is with coordinates: "*/ << endl << "X=" << getX() << endl << "Y=" << getY() << endl << "Z=" << getZ() << endl;
}
//въвеждане на вектор (entering a vector)
istream& Vector::ext(istream& in){
	return in;
} 
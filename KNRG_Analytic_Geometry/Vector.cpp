#include "Vector.h"
//�������� ����������� (default constructor)
Vector::Vector(){}
//����������� � ��������� (constructor with parametersO
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
	cout << "Vector constructed\n";
}
//���� ����������� (copy constructor) 
Vector::Vector(const Vector& rhs) 
{
	Vector tmp(rhs.getX(), rhs.getY(), rhs.getZ());
}
//������������� �� �������� = (redefining of = operator)
Vector& Vector::operator=(const Vector& rhs)
{
	if (this != &rhs) {
		Point::operator=(rhs);
	}
	return *this;
}
//���������� (destructor)
Vector::~Vector() {
	cout << "v desc\n";
}
//������ 2 (task 2)
//������� �� �������� �� ������� �� ������ (function for finding the lenght of a vector)
double Vector::dulzhinaVector()
{
	//cout << sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
	return sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
}
//������� �� �������� �� ������ �� ������ (function of finding the direction of a vector)
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
//������� �� �������� ���� �������� � ����� (function for finding if vector is null)
bool Vector::zeroVector() {
	return (getX() == 0 && getY() == 0 && getZ() == 0);
}
//������� �� �������� ���� �������� � ��������� ������ ���� ������ (function for finding if cector is parallel for other vector)
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
//������� �� �������� ���� �������� � ��������������� �� ���� ������ (function for finding if vector is perpendicular to other vector)
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
//������ 3 (task 3)
//������������� �� �������� + [�������� �� ��� �������] (redefining of + operator [additon of two vectors])
Vector Vector::operator+(const Vector& rhs) {
	cout << "Result after addition is new vector with coordinates: " << endl;
	return Vector(getX() + rhs.getX(), getY() + rhs.getY(), getZ() + rhs.getZ());
}
//������������� �� �������� - [��������� �� ��� �������] (redefining of - operator [substraction of two vectors])
Vector Vector::operator-(const Vector& rhs) {
	cout << "Result after substraction is new vector: " << endl;
	return Vector(getX() - rhs.getX(), getY() - rhs.getY(), getZ() - rhs.getZ());
}
//������������� �� �������� ^ [�������� ������������ �� ��� �������](redefining of ^ operator [vector multiplication of two vectors])
Vector Vector::operator^(const Vector& v) {
	cout << "Result after vector multiplication of two vectors is new vector: " << endl;
	return Vector(getX() * v.getX(), getY() * v.getY(), getZ() * v.getZ());
}
//������������� �� �������� * [�� ��������� �� ������ � ���� ������] (redefining of * operator [for multiplication of a vector with another vector]) 
double Vector::operator*(const Vector& rhs) {
	std::cout << "The result after multiplication is a real number with value ";
	return getX() * rhs.getX() + getY() * rhs.getY() + getZ() * rhs.getZ();
}
//������������� �� �������� * [�� ��������� �� ������ � ������ �����] (redefining of * operator [for multiplication of a vector with a real number])
Vector Vector::operator*(const double a) {
	std::cout << "The result after multiplication is a new vector with coordinates ";
	return Vector(getX() * a, getY() * a, getZ() * a);
}
//������������� �� ��������() [�� ��������� �� 3 �������] (redefining of () operator [for multiplication of 3 vectors])
double Vector::operator()(const Vector& v2, const Vector& v3) {
	cout << "Result after multiplication: " << endl;
	return (this->getY() * v2.getZ() - v2.getY() * this->getZ()) * v3.getX() - (this->getX() * v2.getZ() - v2.getX() * this->getZ()) * v3.getY() + (this->getX() * v2.getY() - this->getY() * v2.getX()) * v3.getZ();
}
//���������� �� ������ (printing a vector)
ostream& Vector::ins(ostream& out)const {
	return out /*<< "Vector is with coordinates: "*/ << endl << "X=" << getX() << endl << "Y=" << getY() << endl << "Z=" << getZ() << endl;
}
//��������� �� ������ (entering a vector)
istream& Vector::ext(istream& in){
	return in;
} 
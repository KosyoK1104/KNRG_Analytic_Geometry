#include "Tetrahedron.h"
Tetrahedron::Tetrahedron(Point& a, Point& b, Point& c, Point& d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	t1 = Triangle(a, b, c);
	t2 = Triangle(a, b, d);
	t3 = Triangle(b, c, d);
	t4 = Triangle(c, a, d);
}

//���� ����������� (copy constructor)
Tetrahedron::Tetrahedron(const Tetrahedron& rhs)
{
	this->a = rhs.a;
	this->b = rhs.b;
	this->c = rhs.c;
	this->d = rhs.d;
	this->t1 = rhs.t1;
	this->t2 = rhs.t2;
	this->t3 = rhs.t3;
	this->t4 = rhs.t4;
}

//������������� �� �������� = (redefining of = operator)
Tetrahedron& Tetrahedron::operator=(const Tetrahedron& rhs) {

	if (this != &rhs)
	{
		this->a = rhs.a;
		this->b = rhs.b;
		this->c = rhs.c;
		this->d = rhs.d;
		this->t1 = rhs.t1;
		this->t2 = rhs.t2;
		this->t3 = rhs.t3;
		this->t4 = rhs.t4;
	}
	return *this;
}

//���������� (destrucror)
Tetrahedron::~Tetrahedron()
{
	std::cout<<"Tetrahedron distructing..."<<std::endl;
}

//�������, ����� ��������� ���� ������ ������ �� ����� (function that checks if all sides are equal)
bool Tetrahedron::vsichkiStraniSaRavni() const
{
	bool saRavni = t1.getA() == t1.getB() == t1.getC() ==
		t2.getA() == t2.getC() == t3.getC();

	return saRavni;
}

//������� �� ����������� �� ���� �� ���������� (function for calculating surface area)
double Tetrahedron::izchisliLiceNaPovurhnina()
{
	return t2.findTriangleSurface() + t3.findTriangleSurface() +t4.findTriangleSurface();
}

//������� �� ����������� �� ���� (function for calculating volume)
double Tetrahedron::izchisliObem()
{
	Vector ab(a, b);
	Vector ac(a, c);
	Vector ad(a, d);
	return fabs((ab(ac,ad))) / 6;
}

bool Tetrahedron::operator<(Point& rhs)
{
	return t1<rhs || t2<rhs || t3<rhs || t4<rhs;

}

bool Tetrahedron::operator>(Point&)
{
	return false;
}

bool Tetrahedron::operator==(Point& rhs)
{
	return t1 == rhs || t2 == rhs || t3 == rhs || t4 == rhs;
}

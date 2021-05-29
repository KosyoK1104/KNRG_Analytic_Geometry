#include "Tetrahedron.h"
Tetrahedron::Tetrahedron(Point& a, Point& b, Point& c, Point& d)
{

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
	return t1.findTriangleSurface() + t2.findTriangleSurface() + t3.findTriangleSurface() + t4.findTriangleSurface();
	//return  sqrt(3) * pow(this->t1.getA(), 2);;
}
//������� �� ����������� �� �������� �� ���������� (function for calculating the height of the tetrahedron)
double Tetrahedron::visochina(double x1, double y1,
	double z1, double a,
	double b, double c,
	double d)
{
	d = fabs((a * x1 + b * y1 +
		c * z1 + d));
	double e = sqrt(a * a + b *
		b + c * c);
	int vis=d/e;
	return vis;
}

//������� �� ����������� �� ���� (function for calculating volume)
double Tetrahedron::izchisliObem()
{
	return (1.0 / 12) * sqrt(2) * pow(this->t1.getA(), 2);
}

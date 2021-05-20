#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(Point& a, Point& b, Point& c, Point& d)
{

}

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

Tetrahedron& Tetrahedron::operator=() {

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
Tetrahedron::~Tetrahedron()
{
	std::cout<<"Tetrahedron distructing..."<<std::endl;
}

bool Tetrahedron::vsichkiStraniSaRavni() const 
{
	const bool saRavni = this->t1.getA() == this->t1.getB() == this->t1.getC() ==
		this->t2.getA() == this->t2.getC() == this->t3.getC();

	return saRavni;
}

double Tetrahedron::izchisliLiceNaPovurhnina() const
{
	const double liceNaPovurhnina = sqrt(3) * pow(this->t1.getA(), 2);

	return liceNaPovurhnina;
}

double Tetrahedron::izchisliObem() const
{
	const double obem = (1.0 / 12) * sqrt(2) * pow(this->t1.getA(), 2);

	return obem;
}


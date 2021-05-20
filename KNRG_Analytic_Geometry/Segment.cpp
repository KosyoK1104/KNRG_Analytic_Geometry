#include "Segment.h"
using namespace std;
Segment::Segment(Point& a, Point& b) 
{
	this->a = a;
	this->b = b;
}

Segment::Segment(const Segment& rhs) 
{
	this->a = rhs.a;
	this->b = rhs.b;
}

Segment& Segment::operator=(const Segment& rhs)
{
	if (this != &rhs)
	{
		this->a = rhs.a;
		this->b = rhs.b;
	}
	return *this;
}

Segment::~Segment() {


}

double Segment::izchisliDulzhina() {
	return this->a.findDistanceToPoint(this->b);
}

Point& Segment::nameriSrednaTochka() const {
	double sx = (this->a.getX() + this->b.getX());
	double sy = (this->a.getY() + this->b.getY());
	double sz = (this->a.getZ() + this->b.getZ());
	Point srednaTochka = Point(sx, sy, sz);

	return srednaTochka;
}

bool Segment::operator==(Point& rhs)
{
	const double razstoqnieA = this->a.findDistanceToPoint(rhs);
	const double razstoqnieB = rhs.findDistanceToPoint(this->b);
	const double dulzhinaOtsechka = this->izchisliDulzhina();

	return razstoqnieA + razstoqnieB == dulzhinaOtsechka;
}
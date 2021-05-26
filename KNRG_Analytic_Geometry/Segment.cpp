#include "Segment.h"
using namespace std;
//конструктор (constructor)
Segment::Segment(Point& a, Point& b) 
{
	this->a = a;
	this->b = b;
}

//копи конструктор (copy constructor)
Segment::Segment(const Segment& rhs) 
{
	this->a = rhs.a;
	this->b = rhs.b;
}

//предефиниране на оператор = (redefining of = operator)
Segment& Segment::operator=(const Segment& rhs)
{
	if (this != &rhs)
	{
		this->a = rhs.a;
		this->b = rhs.b;
	}
	return *this;
}

//деструктор (destructor)
Segment::~Segment() {}
//функция за изчисляване на дължина на отсечка (function for calculation of the lenght of a segment)
double Segment::izchisliDulzhina() {
	return this->a.findDistanceToPoint(this->b);
}

//функция за намиране на среда (function for finding middle of a segment)
Point& Segment::nameriSrednaTochka() const {
	double sx = (a.getX() + b.getX()) / 2;
	double sy = (a.getY() + b.getY()) / 2;
	double sz = (a.getZ() + b.getZ()) / 2;
	Point srednaTochka = Point(sx, sy, sz);

	return srednaTochka;
}

//предефиниране на оператор == (redefining of == operator)
bool Segment::operator==(Point& rhs)
{
	const double razstoqnieA = this->a.findDistanceToPoint(rhs);
	const double razstoqnieB = rhs.findDistanceToPoint(this->b);
	const double dulzhinaOtsechka = this->izchisliDulzhina();

	return razstoqnieA + razstoqnieB == dulzhinaOtsechka;
}
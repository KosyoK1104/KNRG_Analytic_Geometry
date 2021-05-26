#include "Segment.h"
using namespace std;
//конструктор
Segment::Segment(Point& a, Point& b) 
{
	this->a = a;
	this->b = b;
}
//копи конструктор
Segment::Segment(const Segment& rhs) 
{
	this->a = rhs.a;
	this->b = rhs.b;
}
//предефиниране на оператор =
Segment& Segment::operator=(const Segment& rhs)
{
	if (this != &rhs)
	{
		this->a = rhs.a;
		this->b = rhs.b;
	}
	return *this;
}
//деструктор
Segment::~Segment() {


}
//функция за изчисляване на дължина на отсечка
double Segment::izchisliDulzhina() {
	return this->a.findDistanceToPoint(this->b);
}
//функция за намиране на среда
Point& Segment::nameriSrednaTochka() const {
	double sx = (a.getX() + b.getX()) / 2;
	double sy = (a.getY() + b.getY()) / 2;
	double sz = (a.getZ() + b.getZ()) / 2;
	Point srednaTochka = Point(sx, sy, sz);

	return srednaTochka;
}
//предефиниране на оператор ==
bool Segment::operator==(Point& rhs)
{
	const double razstoqnieA = this->a.findDistanceToPoint(rhs);
	const double razstoqnieB = rhs.findDistanceToPoint(this->b);
	const double dulzhinaOtsechka = this->izchisliDulzhina();

	return razstoqnieA + razstoqnieB == dulzhinaOtsechka;
}
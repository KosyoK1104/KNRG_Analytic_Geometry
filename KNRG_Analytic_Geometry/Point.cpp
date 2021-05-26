#include "Point.h"
//дифолтен конструктор
Point::Point() :x(0), y(0), z(0) {};
//конструктор с параметри
Point::Point(double x, double y, double z) { 
	this->x = x;
	this->y = y;
	this->z = z;
};

Point::Point(const Point& p) {
	x = p.getX();
	y = p.getY();
	z = p.getZ();
};
//предефиниране на оператор =
Point& Point::operator=(const Point& p) {
	if (this != &p) {
		x = p.getX();
		y = p.getY();
		z = p.getZ();
	}
	return *this;
}
//деструктор
Point::~Point()
{
	std::cout << "Point destructed\n";
}
//предефиниране на оператор ==
bool Point::operator==(const Point& p) {
	return (x == p.getX()) && (y == p.getY()) && (z == p.getZ());
}
//принтиране
std::ostream& Point::ins(std::ostream& out) const
{ 
	return out << std::endl << "The cordinates of this point are: " << std::endl << "x: " << x << std::endl << "y: " << y << std::endl << "z: " << z << std::endl;
}
//въвеждане
std::istream& Point::ext(std::istream& in)
{
	in >> x >> y >> z;
	return in;
}
//set методи
void Point::setX(double x) { 
	this->x = x; 
};

void Point::setY(double y) { 
	this->y = y; 
};

void Point::setZ(double z) { 
	this->z = z; 
};

//get методи
double Point::getX() const{
	return x;
}

double Point::getY() const {
	return y;
}

double Point::getZ() const {
	return z;
}
//функция за намиране на разстояние до точка
double Point::findDistanceToPoint(const Point& smth)
{
	return sqrt((pow((getX() - smth.getX()), 2))
		+ (pow((getY() - smth.getY()), 2))
		+ (pow((getZ() - smth.getZ()), 2)));
}
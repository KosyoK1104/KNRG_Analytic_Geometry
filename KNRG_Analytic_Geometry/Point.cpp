#include "Point.h"

Point::Point() :x(0), y(0), z(0) {};

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
Point& Point::operator=(const Point& p) {
	if (this != &p) {
		x = p.getX();
		y = p.getY();
		z = p.getZ();
	}
	return *this;
}

Point::~Point()
{
	std::cout << "Point destructed\n";
}

bool Point::operator==(const Point& p) {
	return (x == p.getX()) && (y == p.getY()) && (z == p.getZ());
}

std::ostream& Point::ins(std::ostream& out) const
{
	return out << std::endl << "The cordinates of this point are:" << std::endl << "x: " << x << std::endl << "y: " << y << std::endl << "z: " << z << std::endl;
}

std::istream& Point::ext(std::istream& in)
{
	in >> x >> y >> z;
	return in;
}

void Point::setX(double x) { 
	this->x = x; 
};

void Point::setY(double y) { 
	this->y = y; 
};

void Point::setZ(double z) { 
	this->z = z; 
};


double Point::getX() const{
	return x;
}

double Point::getY() const {
	return y;
}

double Point::getZ() const {
	return z;
}

double Point::findDistanceToPoint(const Point& smth)
{
	return sqrt((pow((getX() - smth.getX()), 2))
		+ (pow((getY() - smth.getY()), 2))
		+ (pow((getZ() - smth.getZ()), 2)));

}
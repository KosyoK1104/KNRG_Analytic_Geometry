#include "Point.h"

Point::Point() :x(0), y(0), z(0) {};

Point::Point(double x, double y, double z) :x(x), y(y), z(z) {};

Point::Point(const Point& p) {
	if (this != &p) {
		x = p.getX();
		y = p.getY();
		z = p.getZ();
	}
}

Point

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

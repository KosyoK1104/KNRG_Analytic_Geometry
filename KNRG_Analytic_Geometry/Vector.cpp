#include "Vector.h"
Vector::Vector() : Point() {}
Vector::Vector(double x, double y, double z) {
	setX(x);
	setY(y);
	setZ(z);
}
Vector::~Vector() {
}
#include "Triangle.h"

Triangle::~Triangle() {}

std::ostream& Triangle::ins(std::ostream& out) const
{
    return std::cout << ' ';
}

std::istream& Triangle::ext(std::istream& in)
{
    return in;
}


Triangle::Triangle() : a(0), b(0), c(0)
{
    this->x = Point(0, 0, 0);
    this->y = Point(0, 0, 0);
    this->z = Point(0, 0, 0);
}






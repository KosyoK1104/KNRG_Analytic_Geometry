#pragma once

#ifndef Point_h
#define Point_h

#include "Element.h"
#include <iostream>

class Point : public Element
{
public:
	Point();
	Point(double x, double y, double z);
	Point(const Point& p);
	Point& operator=(const Point& p);
	~Point();

	bool operator==(const Point& p);

	 void setX(double x);
	 void setY(double y);
	 void setZ(double z);

	 double getX() const;
	 double getY() const;
	 double getZ() const;

	 std::ostream& ins(std::ostream& out);
	 std::istream& ext(std::istream& in) const;

private:
	double x, y, z;
};

std::ostream& operator<<(std::ostream& lhs, Point& rhs);
std::istream& operator>>(std::istream& lhs, Point& rhs);

#endif
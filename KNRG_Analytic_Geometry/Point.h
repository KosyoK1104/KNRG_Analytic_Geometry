#pragma once
#include "Element.h"
#ifndef Point_h
#define Point_h

class Point : public Element
{
public:
	Point();
	Point(double x, double y, double z);
	Point(const Point& p);
	Point& operator=(const Point& p);
	~Point();

	bool operator==(const Point& p);

	virtual std::ostream& ins(std::ostream& out) const;
	virtual std::istream& ext(std::istream& lhs);

	void setX(double x);
	void setY(double y);
	void setZ(double z);

	double getX() const;
	double getY() const;
	double getZ() const;

private:
	double x, y, z;
};

#endif


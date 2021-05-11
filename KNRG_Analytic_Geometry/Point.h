#pragma once
#include "Element.h"
#ifndef Point_h
#define Point_h

class Point : public Element
{
public:
	Point();
	~Point();

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


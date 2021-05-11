#pragma once
#ifndef	Vector_h
#define Vector_h
#include "Point.h"
#include "Element.h"
#include<iostream>
using namespace std;
class Vector : public Point
{

	Vector();
	Vector(double, double, double);
	Vector(const Point&, const Point&);
	Vector& operator=(const Vector&);
	~Vector();


};

#endif
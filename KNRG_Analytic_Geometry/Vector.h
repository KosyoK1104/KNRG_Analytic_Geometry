#pragma once
#ifndef	Vector_h
#define Vector_h
#include "Point.h"
#include "Element.h"
#include<iostream>
#include<cmath>
using namespace std;
class Vector : public Point
{

	Vector();
	Vector(double, double, double);
	Vector(const Point&, const Point&);
	Vector(const Vector& rhs);
	Vector& operator=(const Vector&);
	~Vector();

	//zadacha 2
	double dulzhinaVector();
	Vector posokaVector();

};

#endif
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
public:
	Vector();
	Vector(double, double, double);
	Vector(const Point&, const Point&);
	Vector(const Vector& rhs);
	Vector& operator=(const Vector&);
	~Vector();

	//zadacha 2
	double dulzhinaVector();
	Vector posokaVector();
	bool vectoraENula();
	bool paralelVector(Vector&);
	perpendicularVector(Vector&);


	//zadacha 3
	Vector operator +(const Vector&);
	Vector operator -(const Vector&);
	double operator *(const Vector&);
	double operator()(const Vector&, const Vector&);
	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);

};

#endif
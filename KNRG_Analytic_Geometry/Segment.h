#pragma once
#ifndef	Segment_h
#define Segment_h
#include "Line.h"
using namespace std;
class Segment : public Line
{
public:
	Segment(Point& A, Point& B);
	Segment(const Segment&);
	Segment& operator=(const Segment&);
	~Segment();

	double izchisliDulzhina();
	Point nameriSrednaTochka();
	bool operator==(Point& rhs);
private:
	Point a, b;
};
#endif
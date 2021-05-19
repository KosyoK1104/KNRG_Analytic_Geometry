#pragma once
#include "Point.h"
#include "Triangle.h"
using namespace std;
class Tetrahedron : public Point
{
	public:
		Tetrahedron(Point&, Point&, Point&, Point&);
		Tetrahedron(const Tetrahedron&);
		Tetrahedron& operator=(const Tetrahedron&);
		~Tetrahedron();
		
		double izchisliLiceNaPovurhnina() const;
		double izchisliObem() const ;

		bool operator<(const Point&);
		bool operator>(const Point&);
		bool operator==(const Point&);

	private:
		Point a, b, c, d;
		Triangle t1, t2, t3, t4;
};


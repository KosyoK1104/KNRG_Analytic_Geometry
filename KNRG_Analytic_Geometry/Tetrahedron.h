#pragma once
#include "Point.h"
#include "Triangle.h"
#include "Vector.h"
using namespace std;
class Tetrahedron : public Triangle
{
	public:
		Tetrahedron(Point&, Point&, Point&, Point&);
		Tetrahedron(const Tetrahedron&);
		Tetrahedron& operator=(const Tetrahedron&);
		~Tetrahedron();
		bool vsichkiStraniSaRavni() const;
		double izchisliLiceNaPovurhnina();
		double izchisliObem();
		bool daliEOrtogonalen();
		bool operator<(Point&);
		bool operator>(Point&);
		bool operator==(Point&);

	private:
		Point a, b, c, d;
		Triangle t1, t2, t3, t4;
};


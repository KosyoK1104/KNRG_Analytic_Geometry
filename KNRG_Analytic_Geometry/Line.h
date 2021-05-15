#pragma once
#include "Vector.h"
class Line :
    public Vector
{
public:
    Line();
    Line(const Point&, const Point&);
    Line(const Vector&, const Point&);

    Vector lineDirection();
    Vector findNormalVector();

    int angleTwoLines(Line&);

    Point getPointA();
    Point getPointB();
    Vector getVectorAB();



private:
    Point pointA;
    Point pointB;
    Vector vectorAB;
};



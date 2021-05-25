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

    void angleTwoLines(Line&);

    Point getPointA() const;
    Point getPointB() const;
    Vector getVectorAB() const;

    bool operator||(const Line&);
    bool operator+(const Point&);
    bool operator==(const Line&);
    bool operator&&(const Line&);
    bool operator!=(const Line&);
    bool operator|(const Line&);

private:
    Point pointA;
    Point pointB;
    Vector vectorAB;
};



#pragma once
#include "Vector.h"
class Line :
    public Vector
{
public:
    Line();
    Line(const Point&, const Point&);
    Line(const Vector&, const Point&);
    Line(const Line&);
    Line& operator=(const Line&);
    ~Line();

    Vector lineDirection();
    Vector findNormalVector();

    int angleTwoLines(Line&);

    Point getPointA() const;
    Point getPointB() const;
    Vector getVectorAB() const;


    bool operator||(Line&);
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



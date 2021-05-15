#pragma once
#include "Point.h"
#ifndef Triangle_h
#define Triangle_h

class Triangle :
    public Point
{
public:
    Triangle();
    Triangle(Point&, Point&, Point&);
    Triangle(const Triangle&);

    ~Triangle();

    void FindTriangleKind() const;
    double FindTriangleSurface() const;
    double FindTrianglePerimeter() const;
   
    virtual std::ostream& ins(std::ostream&)const;
    virtual std::istream& ext(std::istream&);
private :
    Point x, y, z;
    double a, b, c;
};

#endif
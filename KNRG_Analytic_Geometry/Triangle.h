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

    double getA() const;
    double getB() const;
    double getC() const;


    void findTriangleKindS() const;
    void findTriangleKindA() const;
    double findTriangleSurface() const;
    double findTrianglePerimeter() const;
    Point& findTriangleMedicenter() const;

    std::ostream& ins(std::ostream&)const;
    std::istream& ext(std::istream&);

private :
    Point x, y, z;
    double a, b, c;
};

#endif
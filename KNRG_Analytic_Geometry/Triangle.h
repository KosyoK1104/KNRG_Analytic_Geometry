#pragma once
#include "Point.h"
#include "Vector.h"
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

    Point getX() const;
    Point getY() const;
    Point getZ() const;

    void findTriangleKindS() const;
    void findTriangleKindA() const;
    double findTriangleSurface() const;
    double findTrianglePerimeter() const;
    Point findTriangleMedicenter() const;

    bool operator<(Point&);
    bool operator>(Point&);
    bool operator==(Point&);

    std::ostream& ins(std::ostream&)const;
    //std::istream& ext(std::istream&);

private :
    Point x, y, z;
    double a, b, c;
};

#endif
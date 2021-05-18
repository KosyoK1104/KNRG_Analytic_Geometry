#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Triangle.h"
#include <cstdlib>
#include <typeinfo>

void Menu();

Point CreatePointObject();
void ExecutePointOperations();
void ComparePoints();

Vector CreateVectorObject(double x, double y, double z);
Vector CreateVectorObject(Point& a, Point& b);
Vector posokaVector();
void ExecuteVectorOperations();

//Triangle CreateTriangleObject();
//void ExecuteTriangleOperations();

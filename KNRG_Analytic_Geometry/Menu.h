#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Triangle.h"
#include "EqualPointException.h"
#include "VectorLenghtException.h"
#include <cstdlib>
#include <typeinfo>

void Menu();

void CreatePointObject();
void ExecutePointOperations();
void ComparePoints();

void CreateVectorObject(double x, double y, double z);
void CreateVectorObject(Point& a, Point& b);
void ExecuteVectorOperations();

void CreateLineObject(Vector&, Point&);
void CreateLineObject(Point&, Point&);
void ExecuteLineOperations();

//Triangle CreateTriangleObject();
//void ExecuteTriangleOperations();

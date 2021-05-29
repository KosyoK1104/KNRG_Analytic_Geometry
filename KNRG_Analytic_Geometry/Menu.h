#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"
#include "Tetrahedron.h"
#include "EqualPointException.h"
#include "VectorLenghtException.h"
#include <cstdlib>
#include <typeinfo>

void Menu();

void CreatePointObject();
void ExecutePointOperations();
void ComparePoints();

void CreateVectorObject(double, double, double);
void CreateVectorObject(Point&, Point&);
void ExecuteVectorOperations();

void CreateLineObject(Vector&, Point&);
void CreateLineObject(Point&, Point&);
void ExecuteLineOperations();

void CreateSegmentObject(Point&, Point&);
void ExecuteSegmentObject();

void CreateTriangleObject(Point&, Point&, Point&);
void ExecuteTriangleObject();

void CreateTetrahedronObject(Point&, Point&, Point&, Point&);
void ExecuteTetrahedronObject();
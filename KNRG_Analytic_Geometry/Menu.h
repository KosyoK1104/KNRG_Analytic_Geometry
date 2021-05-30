#include <iostream>
#include <fstream>
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

void CreatePointObject(bool);
void ExecutePointOperations(bool);
void ComparePoints(bool);

void CreateVectorObject(double, double, double);
void CreateVectorObject(Point&, Point&);
void ExecuteVectorOperations(bool);

void CreateLineObject(Vector&, Point&);
void CreateLineObject(Point&, Point&);
void ExecuteLineOperations(bool);

void CreateSegmentObject(Point&, Point&);
void ExecuteSegmentObject(bool);

void CreateTriangleObject(Point&, Point&, Point&);
void ExecuteTriangleObject(bool);

void CreateTetrahedronObject(Point&, Point&, Point&, Point&);
void ExecuteTetrahedronObject(bool);
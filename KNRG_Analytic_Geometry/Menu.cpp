#include "menu.h"

using namespace std;

char menuInput[1024];
int cntInput = 0, cntEle = 0;
Element** elementsArr = new Element*[100];
ifstream input;

void Menu()
{
	bool mode;
	int optionSelect;
	cin >> optionSelect;
	

	if (optionSelect == 1) {
		mode = true;
		input.open("Vectors.txt");
	}
	else {
		mode = false;
	}
	while (true)
	{
		if (!input.eof()) {
			cout << "Available objects: \n"
				<< "1. Point\n"
				<< "2. Vector\n"
				<< "3. Line\n"
				<< "4. Segment\n"
				<< "5. Triangle\n"
				<< "6. Tetrahedron\n"
				<< "0. Exit\n";

			cout << "\n";
			cout << "Please select an object: ";
			if (mode) {
				input >> optionSelect;
			}
			else {
				cin >> optionSelect;
			}


			switch (optionSelect)
			{
			case 0:
				exit(EXIT_SUCCESS);
			case 1:
			{
				system("cls");
				ExecutePointOperations(mode);
				break;
			}
			case 2:
			{
				system("cls");
				ExecuteVectorOperations(mode);
				break;
			}
			case 3:
			{
				system("cls");
				ExecuteLineOperations(mode);
				break;
			}
			case 4:
			{
				system("cls");
				ExecuteSegmentObject(mode);
				break;
			}
			case 5:
			{
				system("cls");
				ExecuteTriangleObject(mode);
				break;
			}
			case 6:
			{
				system("cls");
				ExecuteTetrahedronObject(mode);
				break;
			}

			}
		}
		else {
			exit(EXIT_SUCCESS);
		}
	}
	input.close();
	if (elementsArr != nullptr) {
		delete elementsArr;
	}
}

void CreatePointObject(bool mode)
{
	double x, y, z;
	cout << "Enter x coordinate: ";
	if (mode) {
		input >> x;
		cout << x << "\n";
	}
	else {
		cin >> x;
	}
	cout << "Enter y coordinate: ";
	if (mode) {
		input >> y;
	}
	else {
		cin >> y;
	}
	cout << "Enter z coordinate: ";
	if (mode) {
		input >> z;
	}
	else {
		cin >> z;
	}
	elementsArr[++cntEle] = new Point(x, y, z);
}

void ExecutePointOperations(bool mode)
{
	int opt;
	do
	{
		cout << "Avalable Point operations: \n"
			<< "1. Create a new Point\n"
			<< "2. Print Point coordinates\n"
			<< "3. Compare the coordinates of two Points\n"
			<< "0. Exit to Main Menu\n";
		cout << "\n";
		cout << "Please enter your choice: ";
		if (mode) {
			input >> opt;
		}
		else {
			cin >> opt;
		}

		switch(opt)
		{
		case 1:
		{
			if(!mode) system("cls");
			CreatePointObject(mode);
			cout << "\n";
			break;
		}
		case 2:
		{
			if (!mode) system("cls");
			int opt;
			cout << "Please select the point you want to print: ";
			if (mode) {
				input >> opt;
			}
			else {
				cin >> opt;
			}
			cout << *elementsArr[opt];
			cout << "\n";
			break;
		}
		case 3:
		{
			if (!mode) system("cls");
			ComparePoints(mode);
			cout << "\n";
			break;
		}
		default:
			if (!mode) system("cls");
			cout << "Please choose a valid option from the list below\n";
			cout << "\n";
			break;
		}
	} while (opt != 0);
}

void ComparePoints(bool mode)
{
	unsigned int opt1, opt2;
	if (mode) {
		input >> opt1;
		input >> opt2;
	}
	else {
		cout << "First Point: ";
		cin >> opt1;
		cout << "Second Point: ";
		cin >> opt2;
	}
	

	if (typeid(elementsArr[opt1]) == typeid(elementsArr[opt2])) 
	{
		if(*static_cast<Point*>(elementsArr[opt1]) == *static_cast<Point*>(elementsArr[opt2]))
		{
			cout << *elementsArr[opt1] << endl;
			cout << "Points are with equal coordinates\n";
		}
		else
		{
			cout << "Points are NOT with equal coordinates\n";
		}
	}
	else {
		cout << "Please choose two objects of type Point";
	}
}

void CreateVectorObject(double x, double y, double z)
{
	elementsArr[++cntEle] = new Vector(x, y, z);
}

void CreateVectorObject(Point& a, Point& b)
{
	elementsArr[++cntEle] = new Vector(a, b);
}

void ExecuteVectorOperations(bool mode)
{
	int opt;
	do {
		cout << "Available vector operations: \n"
			<< "1. Create a vector\n"
			<< "2. Get length\n"
			<< "3. Get direction of vector\n"
			<< "4. Check if vector is null\n"
			<< "5. Check if vector is parallel /w new vector\n"
			<< "6. Check if vector is perpendicular /w new vector\n"
			<< "7. Sum two vectors\n"
			<< "8. Substract two vectors\n"
			<< "9. Multiply vector with real number\n"
			<< "10. Scalar multiply two vectors (result is real number)\n"
			<< "11. Multiply two vectors (result is vector)\n"
			<< "12. Mixed multiplication of three vectors\n"
			<< "0. Exit to Main Menu\n";
		cout << "\n";
		cout << "Please enter your choice: ";
		if (mode) {
			input >> opt;
		}
		else {
			cin >> opt;
		}

		switch (opt)
		{
		case 1:
		{
			if (!mode) system("cls");
			cout << "Available ways to create a vector: \n"
				<< "1. Input with coordinates\n"
				<< "2. Input with points\n"
				<< "0. Exit to Main Menu\n";
			cout << "\n";
			cout << "Please enter your choice: ";
			if (mode) {
				input >> opt;
			}
			else {
				cin >> opt;
			}

			switch (opt)
			{
			case 1:
			{
				if (!mode) system("cls");
				double x, y, z;
				if (mode) {
					input >> x;
					input >> y;
					input >> z;
				}
				else {
					cout << "Enter x coordinate: ";
					cin >> x;
					cout << "Enter y coordinate: ";
					cin >> y;
					cout << "Enter z coordinate: ";
					cin >> z;
				}

				CreateVectorObject(x, y, z);
				cout << "\n";
				break;
			}
			case 2:
			{
				if (!mode) system("cls");
				unsigned int a, b;
				if (mode) {
					input >> a;
					input >> b;
				}
				else {
					cout << "Enter A: \n";
					cin >> a;
					cout << "Enter B: \n";
					cin >> b;
				}
				CreateVectorObject(*dynamic_cast<Point*>(elementsArr[a]), *dynamic_cast<Point*>(elementsArr[b]));
				cout << "\n";
				break;
			}
			}
			break;
		}
		case 2:
		{
			system("cls");
			int opt;
			cout << "Please choose an existing Vector to find it's lenght: ";
			cin >> opt;
			cout << "The lenght of Vector " << opt << " is " << static_cast<Vector*>(elementsArr[opt])->dulzhinaVector() << '\n';
			cout << "\n";
			break;
		}
		case 3:
		{
			if(!mode) system("cls");
			int opt;
			cout << "Please choose an existing Vector to find it's direction: ";
			if (mode) {
				input >> opt;
			}
			else {
				cin >> opt;
			}
	
			try {
				if (static_cast<Vector*>(elementsArr[opt])->zeroVector()) throw VectorLenghtException("The vector is null vector!");
				cout << "The direction of Vector " << opt << " is: " << static_cast<Vector*>(elementsArr[opt])->posokaVector() << '\n';
				cout << "\n";
			}
			catch (VectorLenghtException& e) {
				cerr << "Error: "<< e.what() << "\n";
			}
			break;
		}
		case 4:
		{
			if (!mode) system("cls");
			int opt;
			cout << "Please choose an existing Vector to check if it's zero: ";
			if (mode) {
				input >> opt;
			}
			else {
				cin >> opt;
			}
			if ((static_cast<Vector*>(elementsArr[opt])->zeroVector()) == 1)
			{
				cout << "Vector " << opt << " is zero vector\n";
			}
			else
			{
				cout << "Vector " << opt << " is NOT zero vector\n";
			}
			cout << "\n";
			break;
		}

		case 5:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			cout << "Please choose two vectors to check if they are parallel:\n";
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first vector: ";
				cin >> opt1;
				cout << "Enter the second vector: ";
				cin >> opt2;
			}

			try {
				if (static_cast<Vector*>(elementsArr[opt1])->zeroVector() || static_cast<Vector*>(elementsArr[opt2])->zeroVector()) throw VectorLenghtException("One of the vectors is null vector!");
				if (dynamic_cast<Vector*>(elementsArr[opt1])->paralelVector(*static_cast<Vector*>(elementsArr[opt2])))
				{
					cout << "Vectors are parallel\n";
					cout << "\n";
				}
				else
				{
					cout << "Vectors are not parallel\n";
					cout << "\n";
				}
			}
			catch (VectorLenghtException& e) {
				cerr << "Error: " << e.what() << "\n";
			}
			
			break;
		}
		case 6:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			cout << "Please choose two vectors to check if they are perpendicular:\n";
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first vector: ";
				cin >> opt1;
				cout << "Enter the second vector: ";
				cin >> opt2;
			}

			try {
				if (static_cast<Vector*>(elementsArr[opt1])->zeroVector() || static_cast<Vector*>(elementsArr[opt2])->zeroVector()) throw VectorLenghtException("One of the vectors is null vector!");
				if (dynamic_cast<Vector*>(elementsArr[opt1])->perpendicularVector(*static_cast<Vector*>(elementsArr[opt2])))
				{
					cout << "Vectors are perpendicular" << endl;
					cout << "\n";
				}
				else
				{
					cout << "Vectors are not perpendicular" << endl;
					cout << "\n";
				}
			}
			catch (VectorLenghtException& e) {
				cerr << "Error: " << e.what() << "\n";
			}
			cout << "\n";
			break;
		}
		case 7:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			cout << "Please choose two vectors to sum:\n";
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first vector: ";
				cin >> opt1;
				cout << "Enter the second vector: ";
				cin >> opt2;
			}

			cout << "Result after addition is new vector with coordinates: " << endl;
			cout << (*(static_cast<Vector*>(elementsArr[opt1])) + *(static_cast<Vector*>(elementsArr[opt2]))) << "\n";
			cout << "\n";
			break;
		}
		case 8:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			cout << "Please choose two vectors to substract:\n";
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first vector: ";
				cin >> opt1;
				cout << "Enter the second vector: ";
				cin >> opt2;
			}

			cout << "Result after substraction is new vector: " << endl;
			cout << (*(static_cast<Vector*>(elementsArr[opt1])) - *(static_cast<Vector*>(elementsArr[opt2]))) << "\n";
			cout << "\n";
			break;
		}
		case 9:
		{
			if (!mode) system("cls");
			int opt1;
			double a;
			if (mode) {
				input >> opt1;
				input >> a;
			}else {
				cout << "Please choose an existing Vector: ";
				cin >> opt1;
				cout << "Please enter a real number: ";
				cin >> a;
			}
			std::cout << "The result after multiplication is a new vector with coordinates ";
			cout << *(static_cast<Vector*>(elementsArr[opt1])) * a << "\n";
			cout << "\n";
			break;
		}
		case 10:
		{
			if(!mode) system("cls");
			int opt1, opt2;
			cout << "Please choose two vectors to multiply:\n";
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first vector: ";
				cin >> opt1;
				cout << "Enter the second vector: ";
				cin >> opt2;
			}

			cout << "The result after multiplication is a real number with value ";
			cout << *(static_cast<Vector*>(elementsArr[opt1])) * *(static_cast<Vector*>(elementsArr[opt2])) << "\n";
			cout << "\n";
			break;
		}
		case 11:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			cout << "Please choose two vectors to multiply:\n";
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first vector: ";
				cin >> opt1;
				cout << "Enter the second vector: ";
				cin >> opt2;
			}
			cout << "Result after vector multiplication of two vectors is new vector: " << endl;
			cout << (*(static_cast<Vector*>(elementsArr[opt1])) ^ *(static_cast<Vector*>(elementsArr[opt2]))) << "\n";
			cout << "\n";
			break;
		}
		case 12:
		{
			if(!mode) system("cls");
			int opt1, opt2, opt3;
			cout << "Please choose two vectors and real number to multiply:\n";
			if (mode) {
				input >> opt1;
				input >> opt2;
				input >> opt2;
			}
			else {
				cout << "Enter the first vector: ";
				cin >> opt1;
				cout << "Enter the second vector: ";
				cin >> opt2;
				cout << "Enter the third vector: ";
				cin >> opt3;
			}

			cout << "Result after multiplication: " << endl;
			cout << (*static_cast<Vector*>(elementsArr[opt1]))(*(static_cast<Vector*>(elementsArr[opt2])), *(static_cast<Vector*>(elementsArr[opt3]))) << "\n";
			cout << "\n";
			break;
		}
		default:
			if(!mode) system("cls");
			cout << "Please choose a valid option from the list below\n";
			cout << "\n";
			break;
		}
	} while (opt != 0);
}

void CreateLineObject(Vector& ab, Point& a)
{
	elementsArr[++cntEle] = new Line(ab, a);
}
void CreateLineObject(Point& a, Point& b)
{
	elementsArr[++cntEle] = new Line(a, b);
}
void ExecuteLineOperations(bool mode) 
{
	int opt;
	do 
	{
		cout << "Available line operations: \n"
			<< "1. Create a line\n"
			<< "2. Find the direction of the line\n"
			<< "3. Find the normal vector\n"			
			<< "4. Find the angle between two lines\n"
			<< "5. Check if a point lies on a line\n"
			<< "6. Check if a line is parallel to another line\n"
			<< "7. Check if a line matches to another line\n"
			<< "8. Check if a line intersects another line\n"
			<< "9. Check if a line is crosses another line\n"
			<< "10. Check if a line is perpendicular to another line\n"
			<< "0. Exit to Main Menu\n";
		cout << "\n";
		cout << "Please enter your choice: ";
		if (mode) {
			input >> opt;
		}
		else {
			cin >> opt;
		}

		switch(opt)
		{
		case 1:
		{	
			int opt1;
			do {
				if(!mode) system("cls");
				cout << "Available ways to create a line: \n"
					<< "1. Input with points\n"
					<< "2. Input with vector and point\n"
					<< "0. Exit to Main Menu\n";
				cout << "\n";
				cout << "Please enter your choice: ";
				if (mode) {
					input >> opt;
				}
				else {
					cin >> opt1;
				}
				cout << "\n";

				switch (opt1)
				{
				case 1:
				{
					if(!mode) system("cls");
					unsigned int a, b;
					if (mode) {
						input >> a;
						input >> b;
					}
					else {
						cout << "Enter first point: ";
						cin >> a;
						cout << "Enter second point: ";
						cin >> b;
					}

					CreateLineObject(*dynamic_cast<Point*>(elementsArr[a]), *dynamic_cast<Point*>(elementsArr[b]));
					cout << "Line successfully created!\n";
					cout << "\n";
					break;
				}
				case 2:
				{
					if (!mode) system("cls");
					unsigned int a, b;
					if (mode) {
						input >> a;
						input >> b;
					}
					else {
						cout << "Enter a vector: \n";
						cin >> a;
						cout << "Enter a point: \n";
						cin >> b;
					}
					CreateLineObject(*dynamic_cast<Vector*>(elementsArr[a]), *dynamic_cast<Point*>(elementsArr[b]));
					cout << "Line successfully created!\n";
					cout << "\n";
					break;
				}
				}
			} while (opt1 != 0);
			break;
		}
		case 2:
		{
			if (!mode) system("cls");
			int opt;
			cout << "Enter a line: ";
			if (mode) {
				input >> opt;
			}
			else {
				cin >> opt;
			}
			cout << static_cast<Line*>(elementsArr[opt])->lineDirection() << "\n";
			cout << "\n";
			break;
		}
		case 3:
		{
			if (!mode) system("cls");
			int opt;
			cout << "Enter a line: ";													
			if (mode) {
				input >> opt;
			}
			else {
				cin >> opt;
			}
			cout << static_cast<Line*>(elementsArr[opt])->findNormalVector() << "\n";
			cout << "\n";
			break;
		}
		case 4:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first line: ";
				cin >> opt1;
				cout << "Enter the second line:";
				cin >> opt2;
			}
			cout << static_cast<Line*>(elementsArr[opt1])->angleTwoLines(*static_cast<Line*>(elementsArr[opt2])) << "\n";
			cout << "\n";
			break;
		}
		case 5:
		{
			if(!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter a line: ";
				cin >> opt1;
				cout << "Enter a point: ";
				cin >> opt2;
			}
			if(*(static_cast<Line*>(elementsArr[opt1])) + *(static_cast<Point*>(elementsArr[opt2])))
			{
				cout << "The point lies on the line\n";
				cout << "\n";
			}
			else
			{
				cout << "The point doesn't lie on the line\n";
				cout << "\n";
			}
			break;
		}
		case 6:
		{
			if(!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first line: ";
				cin >> opt1;
				cout << "Enter the second line:";
				cin >> opt2;
			}
			if(*(static_cast<Line*>(elementsArr[opt1])) || *(static_cast<Line*>(elementsArr[opt2])))
			{
				cout << "The lines are parallel\n";
				cout << "\n";
			}
			else
			{
				cout << "The lines are not parallel\n";
				cout << "\n";
			}
			break;
		}
		case 7:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first line: ";
				cin >> opt1;
				cout << "Enter the second line:";
				cin >> opt2;
			}
			if (*(static_cast<Line*>(elementsArr[opt1])) == *(static_cast<Line*>(elementsArr[opt2])))
			{
				cout << "The lines match\n";
				cout << "\n";
			}
			else
			{
				cout << "The lines does not match\n";
				cout << "\n";
			}
			break;
		}
		case 8:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first line: ";
				cin >> opt1;
				cout << "Enter the second line:";
				cin >> opt2;
			}
			if (*(static_cast<Line*>(elementsArr[opt1])) && *(static_cast<Line*>(elementsArr[opt2])))
			{
				cout << "The lines intersect\n";
				cout << "\n";
			}
			else
			{
				cout << "The lines does not intersect\n";
				
				cout << "\n";
			}
			break;
		}
		case 9:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first line: ";
				cin >> opt1;
				cout << "Enter the second line:";
				cin >> opt2;
			}
			if (*(static_cast<Line*>(elementsArr[opt1])) != *(static_cast<Line*>(elementsArr[opt2])))
			{
				cout << "The lines cross eachother\n";
				cout << "\n";
			}
			else
			{
				cout << "The lines does not cross eachother\n";
				cout << "\n";
			}
			break;
		}
		case 10:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter the first line: ";
				cin >> opt1;
				cout << "Enter the second line:";
				cin >> opt2;
			}
			if (*(static_cast<Line*>(elementsArr[opt1])) | *(static_cast<Line*>(elementsArr[opt2])))
			{
				cout << "The lines are perpendicular\n";
				cout << "\n";
			}
			else
			{
				cout << "The lines are not perpendicular\n";
				cout << "\n";
			}
			break;
		}
		default:
			if (!mode) system("cls");
			cout << "Please choose a valid option from the list below\n";
			cout << "\n";
			break;
		}
		
	} while (opt != 0);
}

void CreateSegmentObject(Point& a, Point& b)
{
	elementsArr[++cntEle] = new Segment(a, b);
}

void ExecuteSegmentObject(bool mode)
{
	int opt;
	do
	{
		cout << "Available segment operations: \n"
			<< "1. Create a segment\n"
			<< "2. Get lenght\n"
			<< "3. Get middle point\n"
			<< "4. Check if a point lies on the segment\n"
			<< "0. Exit to Main Menu\n";
		cout << "\n";
		cout << "Please enter your choice: ";
		if (mode) {
			input >> opt;
		}
		else {
			cin >> opt;
		}

		switch (opt)
		{
		case 1:
		{
			if(!mode) system("cls");
			unsigned int a, b;
			if (mode) {
				input >> a;
				input >> b;
			}
			else {
				cout << "Enter first point: ";
				cin >> a;
				cout << "Enter second point: ";
				cin >> b;
			}

			CreateSegmentObject(*static_cast<Point*>(elementsArr[a]), *static_cast<Point*>(elementsArr[b]));
			cout << "Segment successfully created!\n";
			cout << "\n";
			break;
		}
		case 2:
		{
			if(!mode) system("cls");
			int opt1;
			if (mode) {
				input >> opt1;
			}
			else {
				cout << "Enter a segment: ";
				cin >> opt1;
			}
			cout << "The lenght of the segment is: " << static_cast<Segment*>(elementsArr[opt1])->izchisliDulzhina() << "\n";
			cout << "\n";
			break;
		}
		case 3:
		{
			if (!mode) system("cls");
			int opt1;
			if (mode) {
				input >> opt1;
			}
			else {
				cout << "Enter a segment: ";
				cin >> opt1;
			}
			cout << static_cast<Segment*>(elementsArr[opt1])->nameriSrednaTochka() << "\n";
			cout << "\n";
			break;
		}
		case 4:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter a segment: ";
				cin >> opt1;
				cout << "Enter a point: ";
				cin >> opt2;
			}
			if (static_cast<Segment*>(elementsArr[opt1]) == static_cast<Point*>(elementsArr[opt2]))
			{
				cout << "The point lies on the segment\n";
				cout << "\n";
			}
			else
			{
				cout << "The point does not lie on the segment\n";
				cout << "\n";
			}
			break;
		}
		default:
			if (!mode) system("cls");
			cout << "Please choose a valid option from the list below\n";
			cout << "\n";
			break;
		}
	} while (opt != 0);
}

void CreateTriangleObject(Point& a, Point& b, Point& c) {
	elementsArr[++cntEle] = new Triangle(a, b, c);
}

void ExecuteTriangleObject(bool mode)
{
	int opt;
	do
	{
		cout << "Available triangle operations: \n"
			<< "1. Create a triangle\n"
			<< "2. Get the type of a triangle by it's sides\n"
			<< "3. Get the type of a triangle by it's angles\n"
			<< "4. Get triangle's surface\n"
			<< "5. Get triangle's perimeter\n"
			<< "6. Find triangle's medicentre\n"
			<< "7. Check if a point is in triangle\n"
			<< "8. Check if a point is part of triangle's plane\n"	//TRQBVA FIKSACIQ
			<< "9. Check if a point is on one of the sides of a triangle\n"   
			<< "0. Exit to Main Menu\n";
		cout << "\n";
		cout << "Please enter your choice: ";
		if (mode) {
			input >> opt;
		}
		else {
			cin >> opt;
		}

		switch (opt)
		{
		case 1:
		{
			if(!mode) system("cls");
			unsigned int a, b, c;
			if (mode) {
				input >> a;
				input >> b;
				input >> c;
			}
			else {
				cout << "Enter first point: ";
				cin >> a;
				cout << "Enter second point: ";
				cin >> b;
				cout << "Enter third point: ";
				cin >> c;
			}

			try {
				if (a == b) throw EqualPointException("Cannot create triangle while" + to_string(a) + " and " + to_string(b) + " are with same coordinates\n");
				if (a == c) throw EqualPointException("Cannot create triangle while" + to_string(a) + " and " + to_string(c) + " are with same coordinates\n");
				if (b == c) throw EqualPointException("Cannot create triangle while" + to_string(b) + " and " + to_string(c) + " are with same coordinates\n");
				CreateTriangleObject(*static_cast<Point*>(elementsArr[a]), *static_cast<Point*>(elementsArr[b]), *static_cast<Point*>(elementsArr[c]));
				cout << "Triangle successfully created!\n";
				cout << "\n";
			}
			catch (EqualPointException& e) {
				cerr << "Error: " << e.what();
			}
			break;
		}
		case 2:
		{
			if (!mode) system("cls");
			int opt1;
			if (mode) {
				input >> opt1;
			}
			else {
				cout << "Enter a triangle: ";
				cin >> opt1;
			}
			static_cast<Triangle*>(elementsArr[opt1])->findTriangleKindS();
			cout << "\n";
			break;
		}
		case 3:
		{
			if (!mode) system("cls");
			int opt1;
			if (mode) {
				input >> opt1;
			}
			else {
				cout << "Enter a triangle: ";
				cin >> opt1;
			}
			static_cast<Triangle*>(elementsArr[opt1])->findTriangleKindA();
			cout << "\n";
			break;
		}
		case 4:
		{
			if (!mode) system("cls");
			int opt1;
			if (mode) {
				input >> opt1;
			}
			else {
				cout << "Enter a triangle: ";
				cin >> opt1;
			}
			cout << "The triangle's surface is " << static_cast<Triangle*>(elementsArr[opt1])->findTriangleSurface() << "\n";
			cout << "\n";
			break;
		}
		case 5:
		{
			if (!mode) system("cls");
			int opt1;
			if (mode) {
				input >> opt1;
			}
			else {
				cout << "Enter a triangle: ";
				cin >> opt1;
			}
			cout << "The triangle's perimeter is " <<static_cast<Triangle*>(elementsArr[opt1])->findTrianglePerimeter() << "\n";
			cout << "\n";
			break;
		}
		case 6:
		{
			if (!mode) system("cls");
			int opt1;
			if (mode) {
				input >> opt1;
			}
			else {
				cout << "Enter a triangle: ";
				cin >> opt1;
			}
			cout << "The medicentre of the triangle is on these coordinates " << static_cast<Triangle*>(elementsArr[opt1])->findTriangleMedicenter() << "\n";
			cout << "\n";
			break;
		}
		case 7:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter a triangle: ";
				cin >> opt1;
				cout << "Enter a point: ";
				cin >> opt2;
			}

			if (static_cast<Triangle*>(elementsArr[opt1]) < static_cast<Point*>(elementsArr[opt2]))
			{
				cout << "The point is in the triangle\n";
				cout << "\n";
			}
			else
			{
				cout << "The point is not in the triangle\n";
				cout << "\n";
			}
			break;
		}
		case 8:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter a triangle: ";
				cin >> opt1;
				cout << "Enter a point: ";
				cin >> opt2;
			}
			if (static_cast<Triangle*>(elementsArr[opt1]) > static_cast<Point*>(elementsArr[opt2]))
			{
				cout << "The point is in the triangle\n";
				cout << "\n";
			}
			else
			{
				cout << "The point is not in the triangle\n";
				cout << "\n";
			}
			break;
		}
		case 9:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter a triangle: ";
				cin >> opt1;
				cout << "Enter a point: ";
				cin >> opt2;
			}
			if (static_cast<Triangle*>(elementsArr[opt1]) == static_cast<Point*>(elementsArr[opt2]))
			{
				cout << "The point is on the triangle's plane\n";
				cout << "\n";
			}
			else
			{
				cout << "The point is not on the triangle's plane\n";
				cout << "\n";
			}
			break;
		}
		default:
			if (!mode) system("cls");
			cout << "Please choose a valid option from the list below\n";
			cout << "\n";
			break;
		}
	} while (opt != 0);
}

void CreateTetrahedronObject(Point& a, Point& b, Point& c, Point& d) 
{
	if (a == b || a == c || b == c || a == d || b == d || c == d) throw EqualPointException("Cannot create triangle while two or more points are with same coordinations\n");
	elementsArr[++cntEle] = new Tetrahedron(a, b, c, d);
}

void ExecuteTetrahedronObject(bool mode)
{
	int opt;
	do
	{
		cout << "Available triangle operations: \n"
			<< "1. Create a tetrahedron\n"
			<< "2. Check if a tetrahedron is right\n"
			<< "3. Check if the tetrahedron is orthogonal\n"
			<< "4. Get tetrahedron's surrounding surface area\n"
			<< "5. Get tetrahedron's volume\n"
			<< "6. Check if a point is in any of a tetrahedron's sides\n"
			<< "7. Check if a point is part of any of tetrahedron's sides' plane\n"   //TRQBVA FIKSACIQ
			<< "8. Check if a point is on one of the edges of a tetrahedron\n"   
			<< "0. Exit to Main Menu\n";
		cout << "\n";
		cout << "Please enter your choice: ";
		if (mode) {
			input >> opt;
		}
		else {
			cin >> opt;
		}
		switch (opt)
		{
		case 1:
		{
			if(!mode) system("cls");
			unsigned int a, b, c, d;
			if (mode) {
				input >> a;
				input >> b;
				input >> c;
				input >> d;
			}
			else {
				cout << "Enter first point: ";
				cin >> a;
				cout << "Enter second point: ";
				cin >> b;
				cout << "Enter third point: ";
				cin >> c;
				cout << "Enter peak point: ";
				cin >> d;
			}

			try 
			{
				CreateTetrahedronObject(*static_cast<Point*>(elementsArr[a]), *static_cast<Point*>(elementsArr[b]), *static_cast<Point*>(elementsArr[c]), *static_cast<Point*>(elementsArr[d]));
			}
			catch (EqualPointException& e) {
				cerr << "Error: " << e.what();
			}
			CreateTetrahedronObject(*static_cast<Point*>(elementsArr[a]), *static_cast<Point*>(elementsArr[b]), *static_cast<Point*>(elementsArr[c]), *static_cast<Point*>(elementsArr[d]));
			cout << "Tetrahedron successfully created!\n";
			cout << "\n";
			break;
		}
		case 2:
		{
			if (!mode) system("cls");
			int opt1;
			if (mode) {
				input >> opt1;
			}
			else {
				cout << "Enter a Tetrahedron: ";
				cin >> opt1;
			}

			if (static_cast<Tetrahedron*>(elementsArr[opt1])->vsichkiStraniSaRavni()) 
			{
				cout << "The tetrahedron is right\n";
			}
			else 
			{
				cout << "The tetrahedron is not right\n";
			}
			cout << "\n";
			break;
		}
		case 3:
		{
			if (!mode) system("cls");
			int opt;
			if (mode) {
				input >> opt;
			}
			else {
				cout << "Enter a Tetrahedron: ";
				cin >> opt;
			}
			if (static_cast<Tetrahedron*>(elementsArr[opt])->daliEOrtogonalen() == true)
			{
				cout << "The tetrahedron is orthogonal " << endl;
			}
			else
			{
				cout << "The tetrahedron is not orthogonal" << endl;
			}
			break;
		}
		case 4:
		{
			if(!mode) system("cls");
			int opt1;
			if (mode) {
				input >> opt1;
			}
			else {
				cout << "Enter a Tetrahedron: ";
				cin >> opt1;
			}
			cout << "The tetrahedron's surrounding surface is " << static_cast<Tetrahedron*>(elementsArr[opt1])->izchisliLiceNaPovurhnina() << "\n";
			cout << "\n";
			break;
		}
		case 5:
		{
			if (!mode) system("cls");
			int opt1;
			if (mode) {
				input >> opt1;
			}
			else {
				cout << "Enter a Tetrahedron: ";
				cin >> opt1;
			}
			cout << "The tetrahedron's volume is " << static_cast<Tetrahedron*>(elementsArr[opt1])->izchisliObem() << "\n";
			cout << "\n";
			break;
		}
		case 6:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter a tetrahedron: ";
				cin >> opt1;
				cout << "Enter a point: ";
				cin >> opt2;
			}

			if (static_cast<Tetrahedron*>(elementsArr[opt1]) < static_cast<Point*>(elementsArr[opt2]))
			{
				cout << "The point is in the tetrahedron\n";
				cout << "\n";
			}
			else
			{
				cout << "The point is not in the tetrahedron\n";
				cout << "\n";
			}
			break;
		}
		case 7:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter a tetrahedron: ";
				cin >> opt1;
				cout << "Enter a point: ";
				cin >> opt2;
			}
			if (static_cast<Tetrahedron*>(elementsArr[opt1]) > static_cast<Point*>(elementsArr[opt2]))
			{
				cout << "The point is in the tetrahedron\n";
				cout << "\n";
			}
			else
			{
				cout << "The point is not in the tetrahedron\n";
				cout << "\n";
			}
			break;
		}
		case 8:
		{
			if (!mode) system("cls");
			int opt1, opt2;
			if (mode) {
				input >> opt1;
				input >> opt2;
			}
			else {
				cout << "Enter a tetrahedron: ";
				cin >> opt1;
				cout << "Enter a point: ";
				cin >> opt2;
			}
			if (static_cast<Tetrahedron*>(elementsArr[opt1]) == static_cast<Point*>(elementsArr[opt2]))
			{
				cout << "The point is on one of tetrahedron's sides\n";
				cout << "\n";
			}
			else
			{
				cout << "The point is not on one of tetrahedron's sides\n";
				cout << "\n";
			}
			break;
		}
		default:
			if (!mode) system("cls");
			cout << "Please choose a valid option from the list below\n";
			cout << "\n";
			break;
		}
	} while (opt != 0);
}

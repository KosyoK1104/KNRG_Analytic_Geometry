#include "menu.h"

using namespace std;

char menuInput[1024];
int cntInput = 0, cntEle = 0;
Element* elementsArr[100];

void Menu()
{
	int optionSelect;

	while (true)
	{
		cout << "Select an object: \n"
			<< "1. Point\n"
			<< "2. Vector\n"
			<< "3. Line\n"
			<< "4. Segment\n"
			<< "5. Triangle\n"
			<< "6. Tetrahedron\n"
			<< "0. Exit\n";

		cin >> optionSelect;

		switch (optionSelect)
		{
			case 0:
				exit(EXIT_SUCCESS);
			case 1:
			{
				system("CLS");
				Point p(CreatePointObject());
				ExecutePointOperations(p);
				break;
			}
			case 2:
			{
				system("CLS");
				Vector v(CreateVectorObject());
				ExecuteVectorOperations(v);
				break;
			}
			case 3:
			{
				//
			}

		}
	}
}

//Point Create and Execute

Point CreatePointObject()
{
	double x, y, z;
	cout << "Enter x coordinate: \n";
	cin >> x;
	cout << "Enter y coordinate: \n";
	cin >> y;
	cout << "Enter z coordinate: \n";
	cin >> z;
	Point temp(x, y, z);
	elementsArr[cntEle++] = new Point(temp);

	return temp;
}

void ExecutePointOperations(Point& p)
{
	int opt;
	cout << "Avalable Point operations: \n"
		<< "1. Print object\n";
	cin >> opt;

	switch (opt) {
	case 1:
		cout << p;
		break;
	}

	system("pause");
}

//Vector Create and Execute

Vector CreateVectorObject()
{
	double x, y, z;
	cout << "Enter x coordinate: \n";
	cin >> x;
	cout << "Enter y coordinate: \n";
	cin >> y;
	cout << "Enter z coordinate: \n";
	cin >> z;

	Vector temp(x, y, z);
	elementsArr[cntEle++] = new Vector(temp);

	return temp;
}


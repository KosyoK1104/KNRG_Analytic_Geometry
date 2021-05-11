#include "menu.h"

using namespace std;

char menuInput[1024];
int cntInput = 0, entEle = 0;
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
			<< "7. Exit\n";

		cin >> optionSelect;
		switch (optionSelect)
		{
			Point p(CreatePointObject());
			ExecutePointOperations(p);
			break;
		}
		system("CLS");
	}

	Point CreatePointObject()
	{
		int x, y, z;
		cout << "Enter x coordinate: \n";
		cin >> x;
		cout << "Enter y coordinate: \n";
		cin >> y;
		cout << "Enter z coordinate: \n";
		cin >> z;
		Point temp(x, y, z);
		elementsArr[cntElements++] = new Point(temp);

		return temp;
	}

	Vector CreateVectorObject()
	{
		int x, y, z;
		cout << "Enter x coordinate: \n";
		cin >> x;
		cout << "Enter y coordinate: \n";
		cin >> y;
		cout << "Enter z coordinate: \n";
		cin >> z;

		Vector temp(x, y, z);
		elementsArr[cntElements++] = new Vector(temp);

		return temp;
	}
}
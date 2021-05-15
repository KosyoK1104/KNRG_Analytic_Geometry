#include "menu.h"

using namespace std;

char menuInput[1024];
int cntInput = 0, cntEle = 0;
Element** elementsArr = new Element*[100];

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
				system("cls");
				//Point p(CreatePointObject());
				ExecutePointOperations();
				break;
			}
			case 2:
			{
				system("cls");
				//Vector v(CreateVectorObject());
				//ExecuteVectorOperations(v);
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
	elementsArr[++cntEle] = new Point(temp);
	return temp;
}

void ExecutePointOperations()
{
	int opt;
	do
	{
		cout << "Avalable Point operations: \n"
			<< "1. Create a new Point\n"
			<< "2. Print Point coordinates\n"
			<< "3. Compare the coordinates of two Points\n";
		cin >> opt;

		switch(opt)
		{
		case 1:
		{
			CreatePointObject();
			break;
		}
		case 2:
		{
			int opt;
			cin >> opt;
			cout << *elementsArr[opt];
			break;
		}
		case 3:
		{
			ComparePoints();
			break;
		}
		case 0: break;

			system("pause");
		}
	} while (opt != 0);
}

void ComparePoints()
{
	unsigned int opt1, opt2;
	cout << "First Point: \n";
	cin >> opt1;
	cout << "Second Point: \n";
	cin >> opt2;

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
		cout << "Shto si pederast da slagash razlichni obekti";
	}
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

void ExecuteVectorOperations(Vector& v)
{
	int opt;
	std::cout << "Vector operations: \n"
		<< "1. Get length\n"
		<< "2. Get direction of vector\n"
		<< "3. Check if vector is null\n"
		<< "4. Check if vector is parallel /w new vector\n"
		<< "5. Check if vector is perpendicular /w new vector\n"
		<< "6. Make a sum /w new vector \n"
		<< "7. Scalar multiplication /w new vector \n"
		<< "8.Print Vector\n";

	cin >> opt;

	if (opt > 0 && opt < 9)
	{
		switch (opt)
		{
		case 1:
		{
			std::cout << v.dulzhinaVector() << '\n';
			break;
		}
		case 2:
		{
			std::cout << v.posokaVector() << '\n';
			break;
		}
		case 3:
		{
			//std::cout << (std::boolalpha) << v.isVectorNull() << '\n';
			break;
		}
		case 4:
		{
			Vector newV(CreateVectorObject());
			//std::cout << (std::boolalpha) << v.vectorParallelism(newV) << '\n';
			break;
		}
		case 5:
		{
			Vector newV(CreateVectorObject());
			//std::cout << (std::boolalpha) << v.vectorPerpendicularity(newV) << '\n';
			break;
		}
		case 6:
		{
			Vector newV(CreateVectorObject());
			//std::cout << (std::boolalpha) << v + newV << '\n';
			break;
		}
		case 7:
		{
			Vector newV(CreateVectorObject());
			//std::cout << v * newV << '\n';
			break;
		}
		case 8:
		{
			cout << v << '\n';
			break;
		}
		default:
			break;
		}
	}

	system("pause");
}
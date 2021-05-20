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
				ExecuteVectorOperations();
				break;
			}
			case 3:
			{
				system("cls");
				//ExecuteTriangleOperations();
				break;

			}

		}
	}
}

//Point Create and Execute

void CreatePointObject()
{
	double x, y, z;
	cout << "Enter x coordinate: ";
	cin >> x;
	cout << "Enter y coordinate: ";
	cin >> y;
	cout << "Enter z coordinate: ";
	cin >> z;
	elementsArr[++cntEle] = new Point(x, y, z);
}

void ExecutePointOperations()
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
		cin >> opt;

		switch(opt)
		{
		case 1:
		{
			system("cls");
			CreatePointObject();
			cout << "\n";
			break;
		}
		case 2:
		{
			system("cls");
			int opt;
			cout << "Please select the point you want to print: ";
			cin >> opt;
			cout << *elementsArr[opt];
			cout << "\n";
			break;
		}
		case 3:
		{
			system("cls");
			ComparePoints();
			cout << "\n";
			break;
		}
		case 0: 
			break;
			system("pause");
		}
	} while (opt != 0);
}

void ComparePoints()
{
	unsigned int opt1, opt2;
	cout << "First Point: ";
	cin >> opt1;
	cout << "Second Point: ";
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

void CreateVectorObject(double x, double y, double z)
{
	elementsArr[++cntEle] = new Vector(x, y, z);
}

void CreateVectorObject(Point& a, Point& b)
{
	elementsArr[++cntEle] = new Vector(a, b);
}

void ExecuteVectorOperations()
{
	int opt;
	do {
		std::cout << "Available vector operations: \n"
			<< "1. Create a vector\n"
			<< "2. Get length\n"
			<< "3. Get direction of vector\n"
			<< "4. Check if vector is null\n"
			<< "5. Check if vector is parallel /w new vector\n"
			<< "6. Check if vector is perpendicular /w new vector\n"
			<< "7. Make a sum /w new vector \n"
			<< "8. Scalar multiplication /w new vector \n"
			<< "9. Print Vector\n"
			<< "0. Exit to Main Menu\n";
		cout << "\n";
		cout << "Please enter your choice: ";
		cin >> opt;

		switch (opt)
		{
		case 1:
		{
			system("cls");
			cout << "Available ways to create a vector: \n"
				<< "1. Input with coordinates\n"
				<< "2. Input with points\n"
				<< "0. Exit to Main Menu\n";
			cout << "\n";
			cout << "Please enter your choice: ";
			cin >> opt;

			switch (opt)
			{
			case 1:
			{
				system("cls");
				double x, y, z;
				cout << "Enter x coordinate: ";
				cin >> x;
				cout << "Enter y coordinate: ";
				cin >> y;
				cout << "Enter z coordinate: ";
				cin >> z;
				CreateVectorObject(x, y, z);
				cout << "\n";
				break;
			}
			case 2:
			{
				system("cls");
				unsigned int a, b;
				cout << "Enter A: \n";
				cin >> a;
				cout << "Enter B: \n";
				cin >> b;
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
			system("cls");
			int opt;
			cout << "Please choose an existing Vector to find it's direction: ";
			cin >> opt;
			cout << "The direction of Vector " << opt << " is: " << static_cast<Vector*>(elementsArr[opt])->posokaVector() << '\n';
			cout << "\n";
			break;
		}
		case 4:
		{
			system("cls");
			int opt;
			cout << "Please choose an existing Vector to check if it's zero: ";
			cin >> opt;
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

		// DO TUKA SICHKO BACHKA NE BARAI

		case 5:
		{
			system("cls");
			int opt1, opt2;
			cout << "Please choose two vectors to check if they are parallel";
			cin >> opt1 >> opt2;
			dynamic_cast<Vector*>(elementsArr[opt1])->paralelVector(dynamic_cast<Vector*>(elementsArr[opt2]));
			break;
		}
		case 6:
		{
			//Vector newV(CreateVectorObject());
			//std::cout << (std::boolalpha) << v + newV << '\n';
			break;
		}
		case 7:
		{
			//Vector newV(CreateVectorObject());
			//std::cout << v * newV << '\n';
			break;
		}
		case 8:
		{
			//cout << v << '\n';
			break;
		}
		default:
			break;
		}
	} while (opt > 0 && opt < 9 );
}

/*Triangle CreateTriangleObject()
{


}*/
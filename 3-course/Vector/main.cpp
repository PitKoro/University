#include<iostream>
#include "vector.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int choice;
	Vector V1, V2;

	do
	{
		cout << "Work with vectors" << endl;
		cout << "Create vector 1                 1" << endl;
		/*cout << "Create vector 2                 2" << endl;
		cout << "Addition of  nomber             3" << endl;
		cout << "Subtraction of  nomber          4" << endl;
		cout << "Addition of vectors             5" << endl;
		cout << "Subtraction of vectors          6" << endl;
		cout << "Assignment operation            7" << endl;
		cout << "Equality test                   8" << endl;
		cout << "Copy constructor                9" << endl;
		cout << "Print V1 and V2                10" << endl;*/
		cout << "EXIT                            0" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Create vector 1" << endl;
			cout << "Vector dimension: ";
			int vectorDimension;
			cin >> vectorDimension;
			double* v = new double[vectorDimension];
			cout << "Enter the coordinates of the vector: " << endl;
			for (int i = 0; i < vectorDimension; i++)
			{
				cin >> v[i];
			}
			V1.add(vectorDimension, v);
			cout << "Vector1: ";
			V1.print();
			break;
		}
		case 2:
		{
			break;
		}

		default:
			break;
		}
	} while (choice != 0);

}

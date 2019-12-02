#include<iostream>
#include<cstdlib>
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
		system("cls");
		cout << "Work with vectors" << endl;
		cout << "Create vector 1 and vector2     1" << endl;
		cout << "Addition of  number             2" << endl;
		cout << "Subtraction of  number          3" << endl;
		cout << "Addition of vectors             4" << endl;
		cout << "Subtraction of vectors          5" << endl;
		cout << "Assignment operation            6" << endl;
		cout << "Equality test                   7" << endl;
		cout << "Copy constructor                8" << endl;
		cout << "Print V1 and V2                 9" << endl;
		cout << "EXIT                            0" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			system("cls");
			cout << "Create vector 1 and vector2     1" << endl << endl;
			cout << "Create vector1" << endl;
			cout << "Vector1 dimension: ";
			int vector1_Dimension;
			cin >> vector1_Dimension;
			double* v1 = new double[vector1_Dimension];
			cout << "Enter the coordinates of the vector: " << endl;
			for (int i = 0; i < vector1_Dimension; i++)
			{
				cin >> v1[i];
			}
			V1.add(vector1_Dimension, v1);
			cout << "Vector1: " << endl;
			V1.print();
			cout << "-------------------------------------" << endl;
			cout << "Create vector2" << endl;
			cout << "Vector2 dimension: ";
			int vector2_Dimension;
			cin >> vector2_Dimension;
			double* v2 = new double[vector2_Dimension];
			cout << "Enter the coordinates of the vector: " << endl;
			for (int i = 0; i < vector2_Dimension; i++)
			{
				cin >> v2[i];
			}
			V2.add(vector2_Dimension, v2);
			cout << "Vector2: " << endl;
			V2.print();
			cout << endl;
			cout << "=====================================\n";
			delete[] v1;
			delete[] v2;
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout<<"Addition of  number             2"<<endl;
			int vecN;
			double num;
			cout<<"Enter number of vector to addition "<<endl;
			cin>>vecN;
			if(vecN==1)
				{
					cout<<"Enter number"<<endl;
					cin>>num;
					cout<<"V1: "<<endl;
					V1.print();
					V1 = V1 + num;
					cout<<"V1 after addition " << num << " :" << endl;
					V1.print();
				}
			else
				if(vecN==2)
					{
						cout << "Enter number" << endl;
						cin >> num;
						cout << "V2:" << endl;
						V2.print();
						V2 = V2 + num;
						cout << "V2 after addition of nomber "<< num << " :" << endl;
						V2.print();
					}
				else
					{
						cout<<"*ERROR* Try '2' again"<<endl;
						break;
					}
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout<<"Subtraction of  number             3"<<endl;
			int vecN;
			double num;
			cout<<"Enter number of vector to subtraction "<<endl;
			cin>>vecN;
			if(vecN==1)
				{
					cout<<"Enter number"<<endl;
					cin>>num;
					cout<<"V1: "<<endl;
					V1.print();
					V1 = V1 - num;
					cout<<"V1 after subtraction " << num << " :" << endl;
					V1.print();
				}
			else
				if(vecN==2)
					{
						cout << "Enter number" << endl;
						cin >> num;
						cout << "V2:" << endl;
						V2.print();
						V2 = V2 - num;
						cout << "V2 after subtraction of number "<< num << " :" << endl;
						V2.print();
					}
				else
					{
						cout<<"*ERROR* Try '2' again"<<endl;
						break;
					}
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout<<"Addition of vectors             4"<<endl;
			Vector V;
			cout<<"V1:"<<endl;
			V1.print();
			cout<<"V2:"<<endl;
			V2.print();
			V = V1 + V2;
			cout<<"V: "<<endl;
			V.print();
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			cout<<"Subtraction of vectors             5"<<endl;
			Vector V;
			cout<<"V1:"<<endl;
			V1.print();
			cout<<"V2:"<<endl;
			V2.print();
			V=V1-V2;
			cout<<"V:"<<endl;
			V.print();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			cout<<"Assignment operation               6"<<endl;
			cout<<"V1:"<<endl;
			Vector V3, V4;
			int t;
			cout<<"Enter vector number to assignment"<<endl;
			cin>>t;
			if(t==1)
				{
					V3=V4=V1;
					cout<<"V1:"<<endl;
					V1.print();
				}
			else
				if(t==2)
					{
						V3=V4=V2;
						cout<<"V2:"<<endl;
						V2.print();
					}
				else
					{
						cout<<"Error. Try '6' again"<<endl;
						break;
					}
			cout<<"V3:"<<endl;
			V3.print();
			cout<<"V4:"<<endl;
			V4.print();
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			cout<<"Equality test                      7"<<endl;
			cout<<"V1:"<<endl;
			V1.print();
			cout<<"V2:"<<endl;
			V2.print();
			if(V1!=V2)
				cout<<"V1 and V2 are not equal"<<endl;
			else
				cout<<"V1 and V2 are equal"<<endl;
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			cout<<"Copy constructor         8"<<endl;
			Vector V=V1;
			cout<<"V1:"<<endl;
			V1.print();
			cout<<"V:"<<endl;
			V.print();
			cout<<"By value:"<<endl;
			if(V1==V)
				cout<<"V1 and V are equal"<<endl;
			else
				cout<<"V1 and V are not equal"<<endl;
			cout<<"By adress:"<<endl;
			if(&V1 != &V)
				cout<<"Adress of V1 and adress of V are not equal"<<endl;
			else
				cout<<"Adress of V1 and adress of V are equal"<<endl;
			system("pause");
			break;
		}
		case 9:
		{
			system("cls");
			cout<<"Print V1 and V2                9"<<endl;
			cout<<"Vector1: "<<endl;
			V1.print();
			cout << "-------------------------------------" << endl;
			cout<<"Vector2: "<<endl;
			V2.print();
			system("pause");
			break;
		}

		default:
			break;
		}
	} while (choice != 0);

	return 0;
}

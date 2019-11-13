#include <iostream>
#include "XList.h"

using namespace std;

// Включаем работу с XList2 вместо XList
//#define XList XList2
//#define string char*

void add(XList* list);
void remove(XList* list);
void getMark(XList* list);
void setMark(XList* list);
void print(XList* list);




int main()
{
	int answer = -1;

	XList* list = new XList(3);

	while (answer != 0) {
		std::cout << "0 -- Exit" << std::endl;
		std::cout << "1 -- Add" << std::endl;
		std::cout << "2 -- Remove" << std::endl;
		std::cout << "3 -- Get mark" << std::endl;
		std::cout << "4 -- Set mark" << std::endl;
		std::cout << "5 -- Print" << std::endl;

		std::cin >> answer;

		switch (answer) {
		case 1:
			add(list);
			break;

		case 2:
			remove(list);
			break;

		case 3:
			getMark(list);
			break;

		case 4:
			setMark(list);
			break;

		case 5:
			print(list);
			break;

		default:
			break;
		}
	}
	return 0;
}


void add(XList* list)
{
	string name;
	cout << "FIO: ";
	cin >> name;
	list->add(name);
}

void remove(XList* list)
{
	string name;
	cout << "FIO: ";
	cin >> name;
	list->remove(name);
}

void getMark(XList* list)
{
	string name; int mark;

	cout << "FIO: ";
	cin >> name;
	mark = list->getMark(name);
	cout << "mark: " << mark << endl;
}

void setMark(XList* list)
{
	string name; int mark;
	cout << "FIO: "; cin >> name;
	cout << "mark: "; cin >> mark;

	list->setMark(name, mark);
}


void print(XList* list)
{
	list->print();
}

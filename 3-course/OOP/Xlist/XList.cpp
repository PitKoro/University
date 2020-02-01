#include<iostream>
#include"XList.h"

using namespace std;

XList::XList(int maxsize /*= 100*/)
{
    this->maxsize = maxsize;
	this->ourStudent = new  Student[maxsize]; // Выделяем место под ведомость (максимум 100 позиций)

}

XList::~XList()
{
	delete[] ourStudent;
}

void XList::add(string name)
{
	for (int i = 0; i < this->maxsize; i++)
	{
		if (this->ourStudent[i].isEmpty == true)
		{
			this->ourStudent[i].name = name;
			this->ourStudent[i].isEmpty = false;
			break;
		}
	}
}

void XList::remove(string name)
{
	for (int i = 0; i < this->maxsize; i++)
	{
		if (this->ourStudent[i].name == name)
		{
			this->ourStudent[i].name = "";
			this->ourStudent[i].mark = 0;
			this->ourStudent[i].isEmpty = true;
		}
	}
}

void XList::setMark(string name, int mark)
{
	for (int i = 0; i < this->maxsize; i++)
	{
		if (this->ourStudent[i].name == name)
		{
			this->ourStudent[i].mark = mark;
		}
	}
}

int XList::getMark(string name)
{
	for (int i = 0; i < this->maxsize; i++)
	{
		if (this->ourStudent[i].name == name)
		{
			return this->ourStudent[i].mark;
		}
	}
	return 0;
}

void XList::print()
{
	cout << "Name\t" << "mark\t\n";
	cout << "========================\n";
	for (int i = 0; i < this->maxsize; i++)
	{
	    if(this->ourStudent[i].isEmpty == true && this->ourStudent[i].mark == 0)
            cout << "EMPTY" << endl;
        else
            cout << this->ourStudent[i].name << "\t" << this->ourStudent[i].mark << endl;
	}
	cout << "========================\n";
}

#pragma once
#include<iostream>

using namespace std;

struct Student
{
	string name; //Имя студента
	int mark = 0; //Оценка за экзамен
	bool isEmpty = true;
};

class XList
{
public:
	XList(int maxsize);
	XList() : XList(100) {}
	~XList();

	void add(string name); // Добавить студента
	void remove(string name); // Удалить студента
	void setMark(string name, int mark); // Записать отметку
	int getMark(string name); // Если нет оценки или студента вернуть 0
	void print(); //распечатать состояние объекта
private:
	Student* ourStudent; // Объевляем указатель на массив студентов

	int maxsize = 100; // Максимальное число позиций ведомости
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
class XList2
{
    XList* worker = NULL;
public:
    XList2(int maxsize)
    {
        cout<< "--------XList2--------" << endl;
        worker = new XList(maxsize);

    }

    ~XList2()
    {
        delete worker;
    }

	void add(char* name)
	{
	    string tmp = name;
	    worker->add(tmp);
	}

	void remove(char* name) // Удалить студента
	{
	    worker->remove(string(name));
	}
	void setMark(char* name, int mark) // Записать отметку
	{
	    worker->setMark(string(name), mark);
	}
	int getMark(char* name) // Если нет оценки или студента вернуть
	{
        worker->getMark(string(name));
	}
	void print() //распечатать состояние объекта
	{
	    worker->print();
	}
};

#include<iostream>
#include<cstdlib>//Подключаем, чтобы пользоваться функцией system("pause")

using namespace std;

struct Student
{
    string name;
    int mark;
    //bool isEmpty = true;
};

Student* AddStruct (Student* Obj, const int amount);//Выделяет память для элементов массива структур
void SetData(Student* Obj, const int amount);//Отвечает за ввод данных в структуру
void ShowData(const Student* Obj, const int amount);//Выводит на экран все данные в виде таблицы

 
int main()
{
    //Счетчик студентов
    int StudentAmount = 0;
    //Продолжить или остановить ввод данных
    int YesOrNot = 0;
    //Объявляем указатель(этот указатель пока ни на что не указывает)
    Student* OurStudents = 0;

    do
    {
        OurStudents = AddStruct(OurStudents, StudentAmount);
        SetData(OurStudents, StudentAmount);
        StudentAmount++;
        cout << "Continue data entry? Yes-1, No-0\n\n";
        cout << "Your choose: ";
        cin >> YesOrNot;
        cout << endl;
    } while (YesOrNot != 0);

    ShowData(OurStudents, StudentAmount);
    delete[] OurStudents;
    system("pause");
    return 0;
}
 
Student* AddStruct (Student* Obj, const int amount)
{
    if (amount == 0)
    {
        //Выделение памяти для первой структуры
        Obj = new Student[amount + 1]; 
    }
    else
    {
        Student* tempObj = new Student[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            //Копируем во временный объект, чтобы не потерять данные
            tempObj[i] = Obj[i];
        }
        delete[] Obj;
        Obj = tempObj;        
    }
    
    return Obj;
}


void SetData(Student* Obj, const int amount)
{
    cout << "FIO: ";
    cin >> Obj[amount].name;
    cout << "mark: ";
    cin >> Obj[amount].mark; 
    cout << endl;
}


void ShowData(const Student* Obj, const int amount)
{
    cout << "Name\t" << "mark\t\n";
    cout << "=========================\n";
    for (int i = 0; i < amount; i++)
    {
        cout << Obj[i].name << "\t" << Obj[i].mark << endl;
    }   
    cout << "========================\n"; 
}

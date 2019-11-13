#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    setlocale(0, "");
    int x,chislo,left,right,n(1),pp;
    cout<<"Введите диапозон и я выберу вам число из этого диапозона: ";
    cin>>left>>right;
    srand(time(0));
    pp=right-left+1;//если задан диапозон от 1 до 3 то pp=3-1+1=3(сколько чисел в данном диапозоне)
    x=rand()%pp+left;
    while(1)
    {

        cout<<"Введите число которое я загадал: \n";
        cin>>chislo;
        if(chislo<x)
            cout<<"Мое число больше вашего\n";
        else if(chislo>x)
            cout<<"Мое число меньше вашего\n";
        else
        {
            cout<<"Поздравляю,вы отгадали число c "<<n<<" попытки!\n";
            break;
        }

        n++;
    }
    system("pause");
    return 0;
    }



#include <iostream>
#include <cstdlib>//Добавляем, чтобы пользоваться функцией system()
using namespace std;

int main()
{
    char name[100];
    cout<<"What is your name?\n";
    cin>>name;
    cout<<"Hello, "<<name<<"!\n";
    system("pause");
    return 0;
}

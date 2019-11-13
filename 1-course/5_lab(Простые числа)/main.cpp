#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main()
{
    setlocale(0,"");
    int a;
    int i;
    bool IsSimple=true;
    cout<<"Введите натуральное число\n";
    cin>>a;
    for(i=2;i<=sqrt(a);++i)
    {
        if(a%i==0){
        cout<<"Ваше число составное"<<endl;
        IsSimple=false;
        break;
        }
    }
    if(IsSimple)
    cout<<"Ваше число простое\n";
    return 0;
}

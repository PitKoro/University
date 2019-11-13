#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(0, "");

    double a;
    cout<<"Введите один из катетов\n";
    cin>>a;
    double b;
    cout<<"Введите второй катет\n";
    cin>>b;
    double x=a*a+b*b;
    double c=sqrt(x);
    double s=(a*b)/2;
    cout<<"гипотенуза треугольника равна "<<c<<"\n";
    cout<<"площадь треугольника равна "<<s<<"\n";

    return 0;
}

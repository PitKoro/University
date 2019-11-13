#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(0, "");
    cout<<"введите коэффициент a\n";
    double a;
    cin>>a;
    cout<<"введите коэффициент b\n";
    double b;
    cin>>b;
    cout<<"введите коэффициент c\n";
    double c;
    cin>>c;
    double D=b*b-4*a*c;
    double sqrtD = sqrt(D);

    if(a==0){
            if (b==0){
                if (c==0)
                {
                    double x;
                    cout<<"x любое число"<<endl;
                }
                else
                {
                     cout<<"Корней нет"<<endl;
                }
            }
            else{
                    double x=(-c)/b;
                    cout<<"x="<<x<<endl;
            }

    }
    else if (D<0)
    {
         cout<<"Решений нет!\n";
    }
    else
        if (D>0)
    {
    double x1 = (-b + sqrtD)/(2*a);
    cout<<"x1="<<x1<<endl;
    double x2=(-b - sqrtD)/(2*a);
    cout<<"x2="<<x2<<endl;
    }
     else
     if (D==0)
    {
     double x=b/(2*a);
        cout<<"x="<<x<<endl;
    }
    system("pause");
    return 0;
}

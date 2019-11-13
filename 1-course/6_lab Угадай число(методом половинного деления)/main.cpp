#include<iostream>
#include <cmath>

using namespace std;

int main()
{

    setlocale(0,"");
    int left,mid,right,x(3),n(1);
    cout<<"Меньше=1, Больше=2, Угадал=0\n";
    cout<<"Введите диапозон натуральных чисел\n";
    cin>>left>>right;
    while(1){
        mid=(left+right)/2;
        cout<<"Ваше число "<<mid<<" ?"<<endl;
        cin>>x;
        if(x==1){
            right=mid;
            mid=(left+right)/2;
        }
        else if(x==2){
            left=mid;
            mid=(left+right)/2;
        }
        else if(x==0){
            cout<<"Победа! Я угадал с "<<n<<" попытки!";
            break;
        }
        n++;
    }


}

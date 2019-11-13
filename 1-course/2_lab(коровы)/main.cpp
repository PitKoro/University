#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(0, "");
    int a;
    int k=1;
    while(k==1)
    {
    cout<<"Сколько коров пасется на лугу?\n\n";
    cin>>a;
    if(a%100<10||a%100>20){
    if (a%10==1)
        cout<<"на лугу пасется "<<a<<" корова\n\n";
    else if (a%10>1&&a%10<5)
        cout<<"на лугу пасется "<<a<<" коровы\n\n";
    else
        cout<<"на лугу пасется "<<a<<" коров\n\n";
    }
    else
        cout<<"на лугу пасется "<<a<<" коров\n\n";

        cout<<"Для продолжения нажмите 1\n\n";
        cin>>k;
    }

    system("pause");
    return 0;
}

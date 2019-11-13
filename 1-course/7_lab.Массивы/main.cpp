#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void reverse(int *array, int size){
    for(int i=0; i<size/2; i++){
        int tmp=array[i];
        array[i]=array[size-i-1];
        array[size-1-i]=tmp;
    }
    cout<<"Вывод: ";
}
void move(int *array, int size){
    int tmp = array[size-1];

        for (int i=size-2;i>=0;i--) {
        array[i+1] = array[i];
        }
        array[0]=tmp;

}
void sort(int *array, int size){

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size- 1 - i; ++j) {
               if (array[j] > array[j+1]) {
                   int tmp = array[j];
                   array[j] = array[j+1];
                   array[j+1] = tmp;

               }

            }
        }

        /*for(int i = 0; i < size; i++){
            cout << array[i] << " ";
        }*/

}
void conclusion( int *array,int size){
    for(int i=0; i<size; i++){
            cout<<array[i]<<" ";
    }
}


int main()
{
    setlocale(LC_ALL,"rus");
    int size;
    cout<<"Размер массива:\n";
    cin>>size;
    cout<<endl;
    int array[size];
    srand(time(0));
    cout<<"Ваш массив: ";
    for(int i=0;i<size;i++){
        array[i]=rand()%100+1;
        cout<<array[i]<<" ";
    }
    int t(1);
    while(t==1){
    cout<<"\n1 - сдвиг элементов массива на m позиций; 2-Отсортировать массив; 3-развернуть массив";
    int choose(4);
    cout<<endl;
    cin>>choose;
    if(choose==1){
        cout<<"На сколько позиций сдвинуть элементы массива?\n";
        int count;
        cin >> count;

        for (int i = 0; i < count; ++i) {
           move(array, size);
        }

        cout << endl;

    } else if(choose==2){
        sort(array, size);
        cout<<endl;
    }else if(choose==3){
        reverse(array,size);
        cout<<endl;
    }
       conclusion(array, size);
       cout<<endl;


    cout<<"\nПродолжить - 1; Выйти - 0\n";
    cin>>t;


    }
    system("pause");
    return 0;
}

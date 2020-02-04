#include <iostream>
#include "matrix3.h"
using namespace std;


int main()
{
	setlocale(LC_ALL,"RUS");
	int rows = 6;//строки
	int lows = 6;//столбцы
	bool answer;

	double** Matrix = memoryAllocation(rows, lows); // Выделяем место под начальную матрицу
	readMatrixFromFile(Matrix,rows,lows ); // Записываем матрицу из файла в массив

	double** UnitToResultMatrix = memoryAllocation(rows, lows); // Создаем единичную матрицу, после поиска обратной сюда запишется обратная матрица
	initialization_of_the_UnitMatrix(UnitToResultMatrix, rows, lows);// Инициализируем единичную матрицу

	int Big_lows = 2*lows; // Количество столбцов в большой матрице
	double** Matrix_Big = memoryAllocation(rows, Big_lows); // Выделяем место под матрицу Matrix_Big в которую запишем элементы Matrix  и  UnitMatrix
	matrixCombination(Matrix_Big, Matrix, UnitToResultMatrix, rows, lows);//Соединяем в одну матрицу

	cout << "Начальная матрица:\n";
	print(Matrix, rows,lows); // Выводим начальную матрицу
	cout << "Единичная матрица:\n";
	print(UnitToResultMatrix, rows, lows);//Выводит единичную матрицу
	cout << "Общая матрица:\n";
	print(Matrix_Big, rows, Big_lows);//Выводим большую матрицу на экран
    cout << "Если вы хотите включить режим демонстрации нажмите 1, иначе 0\n";
    cin >> answer;

    function<void(std::string, double**, int, int)> sp = [](std::string msg, double** Matrix_Big,int rows,int columns){};
    if(answer == true)
    {
        sp = processEvent;
    }
	UnitToResultMatrix = Gauss_method(Matrix_Big, Matrix, rows, lows, sp);// Метод Гаусса

	cout << "Общая матрица после преобразований:\n";
	print(Matrix_Big, rows, Big_lows);//Выводим большую матрицу на экран
	cout << "Обратная матрица:\n";
	print(UnitToResultMatrix, rows, lows); // Выводим обратную матрицу на экран

    cout << "Начальная матрица:\n";
	print(Matrix, rows,lows); // Выводим начальную матрицу

	cout<<"Проверка: умножаем исходную матрицу на обратную:\n";

	double** resultMultiplyMatrix; // Создаем  матрицу 
    resultMultiplyMatrix = multiplyMatrix(Matrix, UnitToResultMatrix, rows); // Записываем результат умножения матриц
    print(resultMultiplyMatrix, rows, lows);
	writingMatrixToFile( UnitToResultMatrix,  rows, lows);

	//Удаление массивов
	for (int i = 0; i < rows; i++)
	{
		delete[]Matrix[i];
		delete[]UnitToResultMatrix[i];
		delete[]Matrix_Big[i];
	}

	delete[]Matrix;
	delete[]UnitToResultMatrix;
	delete[]Matrix_Big;

	return 0;
}

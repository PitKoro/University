#include <iostream>
#include "matrix3.h"
using namespace std;


int main()
{
	setlocale(LC_ALL,"RUS");
	int rows = 3;//строки
	int lows = 3;//столбцы
	
	double** Matrix = memoryAllocation(rows, lows); // Выделяем место под начальную матрицу
	readMatrixFromFile(Matrix,rows,lows ); // Записываем матрицу из файла в массив
	
	double** UnitMatrix = memoryAllocation(rows, lows); // Создаем единичную матрицу
	initialization_of_the_UnitMatrix(UnitMatrix, rows, lows);// Инициализируем единичную матрицу
	
	int Big_lows = 2*lows; // Количество столбцов в большой матрице
	double** Matrix_Big = memoryAllocation(rows, Big_lows); // Выделяем место под матрицу Matrix_Big в которую запишем элементы Matrix  и  UnitMatrix
	matrixCombination(Matrix_Big, Matrix, UnitMatrix, rows, lows);//Соединяем в одну матрицу
	
	cout << "Начальная матрица:\n";
	print(Matrix, rows,lows); // Выводим начальную матрицу 
	cout << "Единичная матрица:\n";
	print(UnitMatrix, rows, lows);//Выводит единичную матрицу
	cout << "Совмещенная матрица:\n";
	print(Matrix_Big, rows, Big_lows);//Выводим большую матрицу на экран

	double** InversMatrix; // Указатель на обратную матрицу, которую мы получим после вызова Gaus_method(...)
	InversMatrix = Gauss_method(Matrix_Big, Matrix, rows, lows);// Метод Гаусса

	cout << "Совмещенная матрица после преобразований:\n";
	print(Matrix_Big, rows, Big_lows);//Выводим большую матрицу на экран
	cout << "Обратная матрица:\n";
	print(InversMatrix, rows, lows); // Выводим обратную матрицу на экран
	
	//Удаление массивов
	for (int i = 0; i < rows; i++)
	{
		delete[]Matrix[i];
		delete[]UnitMatrix[i];
		delete[]Matrix_Big[i];
		delete[]InversMatrix[i];

	}

	delete[]Matrix;
	delete[]UnitMatrix;
	delete[]Matrix_Big;
	delete[]InversMatrix;

	return 0;
}

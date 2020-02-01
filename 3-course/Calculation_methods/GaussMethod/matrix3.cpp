#include<iostream>
#include <fstream>
#include "matrix3.h"
using namespace std;

double** memoryAllocation(int rows, int lows)
{
	double** Matrix = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		Matrix[i] = new double[lows];
	}
	return Matrix;
}

void readMatrixFromFile(double** arr, int rows, int lows)
{
	ifstream matrix3("C:\\Users\\Пётр\\source\\repos\\Lab1\\matrix3.txt");
	if (!matrix3.is_open())
	{
		cout << "*ERROR* FILE NOT OPENED" << endl;
	}
	/*else
	{
		cout << "FILE OPENED\n";
	}*/

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < lows; j++)
		{
			matrix3 >> arr[i][j];
		}
	}
	matrix3.close();
}

void initialization_of_the_UnitMatrix(double** arr, int rows, int lows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < lows; j++)
		{
			if (i == j)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}


void print(double** arr, int rows, int lows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < lows; j++)
		{
			cout << "\t" << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void matrixCombination(double** Matrix_Big, double** Matrix, double** UnitMatrix, int rows, int lows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < lows; j++)
		{
			Matrix_Big[i][j] = Matrix[i][j];
			Matrix_Big[i][j + lows] = UnitMatrix[i][j];
		}
	}
}



double** Gauss_method(double** Matrix_Big, double** Matrix, int rows, int lows)
{
	//Прямой ход (Зануление нижнего левого угла)
	for (int k = 0; k < rows; k++) //k-номер строки
	{
		for (int i = 0; i < 2 * lows; i++) //i-номер столбца
			Matrix_Big[k][i] = Matrix_Big[k][i] / Matrix[k][k]; //Деление k-строки на первый член !=0 для преобразования его в единицу
		for (int i = k + 1; i < rows; i++) //i-номер следующей строки после k
		{
			double K = Matrix_Big[i][k] / Matrix_Big[k][k]; //Коэффициент
			for (int j = 0; j < 2 * lows; j++) //j-номер столбца следующей строки после k
				Matrix_Big[i][j] = Matrix_Big[i][j] - Matrix_Big[k][j] * K; //Зануление элементов матрицы ниже первого члена, преобразованного в единицу
		}
		for (int i = 0; i < rows; i++) //Обновление, внесение изменений в начальную матрицу
			for (int j = 0; j < lows; j++)
				Matrix[i][j] = Matrix_Big[i][j];
	}

	//Обратный ход (Зануление верхнего правого угла)
	for (int k = rows - 1; k > -1; k--) //k-номер строки
	{
		for (int i = 2 * lows - 1; i > -1; i--) //i-номер столбца
			Matrix_Big[k][i] = Matrix_Big[k][i] / Matrix[k][k];
		for (int i = k - 1; i > -1; i--) //i-номер следующей строки после k
		{
			double K = Matrix_Big[i][k] / Matrix_Big[k][k];
			for (int j = 2 * lows - 1; j > -1; j--) //j-номер столбца следующей строки после k
				Matrix_Big[i][j] = Matrix_Big[i][j] - Matrix_Big[k][j] * K;
		}
	}

	//Отделяем от общей матрицы
	double** InversMatrix = memoryAllocation(rows, lows);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < lows; j++)
			InversMatrix[i][j] = Matrix_Big[i][j + lows];
	return InversMatrix;
}

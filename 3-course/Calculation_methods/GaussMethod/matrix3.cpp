#include<iostream>
#include <fstream>
#include <cmath>
#include<cstdlib>
#include <iomanip>

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
	std::string path = "matrix6.txt";
	ifstream matrix3(path);
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
		    if(abs(arr[i][j]) < 0.001)
            {
				cout << "\t";
				printf("%.2f", 0);
				//cout  << " ";
            }else
            {
				cout << "\t";
				printf("%.2f", arr[i][j]);
				if (j == 5)
				{
					cout << " |";
				}
                
            }

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

double** Gauss_method(double** Matrix_Big, double** Matrix, int rows, int lows, function<void(std::string, double**, int, int)> stepProcessor)
{
    double max ;

	//Прямой ход (Зануление нижнего левого угла)
	for (int k = 0; k < rows; k++) //k-номер столбца
	{
	    ///поиск максимального элемента в столбце и поменять местами сторчку с максимальным элементом с первой строчкой
	    int pos = k;
	    max = Matrix_Big[k][k];
	    for(int i = k; i< rows; i++)
        {
            if(max < abs(Matrix_Big[i][k]))
            {
                max = abs(Matrix_Big[i][k]);
                pos = i;

            }
        }

	   swapRows(Matrix_Big[k],Matrix_Big[pos],2*rows);
	   stepProcessor("We found the main element and swap from the first.", Matrix_Big, rows, 2*lows);

		for (int i = k + 1; i < rows; i++) //i-номер следующей строки после k
		{
			double K = Matrix_Big[i][k] / Matrix_Big[k][k]; //Коэффициент
			for (int j = 0; j < 2 * lows; j++) //j-номер столбца следующей строки после k
			{
				Matrix_Big[i][j] = Matrix_Big[i][j] - Matrix_Big[k][j] * K; //Зануление элементов матрицы ниже первого члена, преобразованного в единицу
				
			}
			stepProcessor("Converted: Zero (Forward)", Matrix_Big, rows, 2 * lows);
		}
	}

	//Обратный ход (Зануление верхнего правого угла)
	for (int k = rows - 1; k > -1; k--) //k-номер строки
	{
		for (int i = 2 * lows - 1; i > -1; i--) //i-номер столбца
		{
			Matrix_Big[k][i] = Matrix_Big[k][i] / Matrix_Big[k][k];
			
		}
		stepProcessor("Converted: We divide the line into the main element (Reverse)", Matrix_Big, rows, 2 * lows);

		for (int i = k - 1; i > -1; i--) //i-номер следующей строки после k
		{
			double K = Matrix_Big[i][k] / Matrix_Big[k][k];
			for (int j = 2 * lows - 1; j > -1; j--) //j-номер столбца следующей строки после k
			{
				Matrix_Big[i][j] = Matrix_Big[i][j] - Matrix_Big[k][j] * K;
				
			}
			stepProcessor("Converted: Zero (Reverse)", Matrix_Big, rows, 2 * lows);
				
		}
	}

	//Отделяем от общей матрицы
	double** InversMatrix = memoryAllocation(rows, lows);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < lows; j++)
			InversMatrix[i][j] = Matrix_Big[i][j + lows];
	return InversMatrix;
}

double** multiplyMatrix(double** Matrix, double** ResultMatrix, int rows)
{
    double** resultMultiplyMatrix = memoryAllocation(rows, rows);
    for(int i = 0; i<rows; i++)
    {
        for(int j=0; j<rows; j++)
        {
            resultMultiplyMatrix[i][j] = 0;
            for(int k=0; k<rows; k++)
            {
                resultMultiplyMatrix[i][j]  += Matrix[i][k]*ResultMatrix[k][j];
            }
        }
    }
    return resultMultiplyMatrix;
}

void swapRows(double* arr1, double* arr2, int N)
{
    double tmp;
    for(int i=0;i<N;i++)
    {
        tmp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp;
    }
}

void processEvent(string msg, double** Matrix_Big,int rows,int columns)
{
    cout << msg << endl;
    print(Matrix_Big, rows, columns);
    system("pause");
}

void writingMatrixToFile(double** UnitToResultMatrix, int rows, int lows)// Записывает Обратную Матрицу в Файл
{
	ofstream out; // поток для записи
	std::string path = "inverSSMatrix.txt"; // путь до файла в котором хранится результат работы программы
	out.open(path); // окрываем файл для записи
	if (out.is_open())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < lows; j++)
			{
				out << UnitToResultMatrix[i][j] << "\t";
			}
			out << endl;
		}
	}

}

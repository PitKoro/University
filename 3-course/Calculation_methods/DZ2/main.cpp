#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include<cstdlib>

using namespace std;

void PrintMatrix(double** m, int size)
{
    cout << "MATRIX\n";
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            cout << m[i][j] << " ";
        }

        cout << endl;
    }
}


void PrintVector(double* m, int size)
{
    cout << "VECTOR\n";
    for(int i=0; i<size; i++)
    {
        cout << m[i] << endl;
    }
}


double* multiplyMatrixByVector(double** Matrix, double* x, int rows)
{
    PrintMatrix(Matrix, rows);
    PrintVector(x, rows);

    double* resultMultiplyVector = new double[rows];
    for(int i = 0; i<rows; i++)
    {
        resultMultiplyVector[i] = 0;
        for(int j=0; j<rows; j++)
        {
            resultMultiplyVector[i]  += Matrix[i][j]*x[j];
        }
    }
    return resultMultiplyVector;
}

void toFile(const char* file, int size)
{
	ofstream out(file);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			out << 1 / (pow(3, fabs((i + 1) - (j + 1)) + 1)) << "\t";
		}
		out << endl;
	}
	out << endl;
	out << endl;
	for (int i = 0; i < size; i++)
	{
		out << pow(0.5, cos(i + 1)) << "    ";
	}

	out.close();
}

class Matr
{
public:
	int size = 0;
	double **A;
	double **B;
	double **C;
	double *y;
	double *z;
	double e = 0;

public:

	Matr(int l, double eps)
	{

		size = l;
		A = new double*[l];
		for (int i = 0; i < l; i++)
			A[i] = new double[l];
		B = new double*[l];
		for (int i = 0; i < l; i++)
			B[i] = new double[l];

        C = new double*[l];
		for (int i = 0; i < l; i++)
			C[i] = new double[l];
		y = new double[l];
		z = new double[l];
		e = eps;
	}

	//этот конструктор используется, если надо выгрузить матрицу непосредственно из файла
	Matr(char* file, double eps){

		ifstream in(file);

		in >> size;

		A = new double*[size];
		for (int i = 0; i < size; i++)
			A[i] = new double[size];
		B = new double*[size];
		for (int i = 0; i < size; i++)
			B[i] = new double[size];

        C = new double*[size];
		for (int i = 0; i < size; i++)
			C[i] = new double[size];

		y = new double[size];
		z = new double[size];
		e = eps;

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				in >> A[i][j];
				B[i][j] = A[i][j];
				C[i][j] = A[i][j];

			}

		for (int i = 0; i < size; i++)
		{
			in >> y[i];
			z[i] = y[i];
		}

		in.close();
	}

	double show(int i, int j) { return A[i][j]; };

	//эта функция вызывается только для файла из лабы
	void MakeMatr(const char* file)
	{
		ifstream in(file);

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				in >> A[i][j];
				B[i][j] = A[i][j];
				C[i][j] = A[i][j];

			}
		for (int i = 0; i < size; i++)
		{
			in >> y[i];
			z[i] = y[i];
		}

		in.close();

	}


	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				printf("%3.6f ", show(i, j));
			}
			printf("| %3.3f ", y[i]);
			cout << endl;
		}
	}
	void Preob()
	{
		double temp = 0;

		for (int i = 0; i < size; i++)
		{
			temp = A[i][i];
			y[i] /= temp;
			for (int j = 0; j < size; j++)
			{
				A[i][j] /= temp;
			}
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				A[i][i] = 0;
		}
	}

	double Norma(double **A)
	{
		double sum = 0, max = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				sum += fabs(A[i][j]);
			}
			if (sum > max) max = sum;
			sum = 0;
		}
		cout << "Max: " << max << endl;
		return max;
	}
	double Pogr()
	{
		double eps = 0;
		double norm = Norma(A);
		eps = ((1 - norm) / norm) * e;
		return eps;
	}
	double* Itera()
	{
		double *x = new double[size];
		double *x0 = new double[size];
		double *Err = new double[size];
		double maxErr = 0, per = 0;
		per = Pogr();
		for (int i = 0; i < size; i++)
			x0[i] = 1;
		int counter = 0;
		do
		{
			for (int i = 0; i < size; i++)
			{
				x[i] = y[i];
				for (int j = 0; j < size; j++)
				{
					x[i] -= A[i][j] * x0[j];
				}

				Err[i] = fabs(x[i] - x0[i]);
			}
			maxErr = 0;
			for (int i = 0; i < size; i++)
			{
				if (maxErr < Err[i]) maxErr = Err[i];
				x0[i] = x[i];
			}
			cout << endl << "maxErr = " << maxErr;
			counter++;
		} while (maxErr > per);
		cout << endl << "Количество итераций: " << counter << endl;
		for (int i = 0; i < size; i++)
			cout << "x" << i + 1 << "=" << x[i] << " " << endl;

		//проверка найденного ответа
		double answer = 0, max = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				answer += B[i][j] * x[j];
			}

			answer = fabs(answer - z[i]);
			if (max < answer) {
				max = answer;
			}
			answer = 0;
		}
		cout << "Точность: " << max << endl;

		//delete[] x;
		delete[] x0;
		delete[] Err;
		return x;
	}
};

int main()
{

		setlocale(LC_ALL, "rus");
		int n;
		double e;
		cout << "Введите количество уравнений:   ";
		cin >> n;
		cout << "Введите необходимую точность:  ";
		cin >> e;

		Matr a(n, e);
		toFile("MatrixVector.txt", n);
		a.MakeMatr("MatrixVector.txt");

		cout << endl << "Расширенная матрица:" << endl;
		a.Print();
		a.Preob();
		cout << endl << "Преображенная матрица" << endl;
		a.Print();
		cout << endl;
		double *x = a.Itera();
		cout << endl;
		double* c = multiplyMatrixByVector(a.C, x, n);
		for(int i = 0;i<n;i++)
        {
            cout <<"C" << i+1 << "=" <<  c[i] << endl;
        }


		system("pause");
		return 0;
}
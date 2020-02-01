#include <iostream>
#include "matrix3.h"
using namespace std;


int main()
{
	
	int rows = 3;//������
	int lows = 3;//�������
	
	
	double** Matrix = memoryAllocation(rows, lows); // �������� ����� ��� ��������� �������
	readMatrixFromFile(Matrix,rows,lows ); // ���������� ������� �� ����� � ������
	
	double** UnitMatrix = memoryAllocation(rows, lows); // ������� ��������� �������
	initialization_of_the_UnitMatrix(UnitMatrix, rows, lows);// �������������� ��������� �������



	
	int Big_lows = 2*lows; // ���������� �������� � ������� �������
	double** Matrix_Big = memoryAllocation(rows, Big_lows); // �������� ����� ��� ������� Matrix_Big � ������� ������� �������� Matrix  �  UnitMatrix
	matrixCombination(Matrix_Big, Matrix, UnitMatrix, rows, lows);//��������� � ���� �������
	
	
	print(Matrix, rows,lows); // ������� ��������� ������� 
	print(UnitMatrix, rows, lows);//������� ��������� �������
	print(Matrix_Big, rows, Big_lows);//������� ������� ������� �� �����

	double** InversMatrix; // ��������� �� �������� �������, ������� �� ������� ����� ������ Gaus_method(...)
	InversMatrix = Gauss_method(Matrix_Big, Matrix, rows, lows);// ����� ������


	print(Matrix_Big, rows, Big_lows);//������� ������� ������� �� �����
	print(InversMatrix, rows, lows); // ������� �������� ������� �� �����
	

	//�������� ��������
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










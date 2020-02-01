#pragma once
double** memoryAllocation(int rows, int lows); // ��������� ������ ���  �������
void readMatrixFromFile(double** arr, int rows, int lows); // ������ ������� �� ����� � ������ � ��������� ������������ ������
void initialization_of_the_UnitMatrix(double** arr, int rows, int lows); // ������������� ��������� �������
void print(double** arr, int rows, int lows); // ����� ������� �� �����
void matrixCombination(double** Matrix_Big, double** Matrix, double** UnitMatrix, int rows, int lows); // ��������� ������ ������� � ���������

double** Gauss_method(double** Matrix_Big, double** Matrix, int rows, int lows); // ����� ������

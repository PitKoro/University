#pragma once
double** memoryAllocation(int rows, int lows); // Выделение памяти под  матрицу
void readMatrixFromFile(double** arr, int rows, int lows); // Чтение матрицы из файла и запись в двумерный динамический массив
void initialization_of_the_UnitMatrix(double** arr, int rows, int lows); // Инициализация единичной матрицы
void print(double** arr, int rows, int lows); // Вывод матрицы на экран
void matrixCombination(double** Matrix_Big, double** Matrix, double** UnitMatrix, int rows, int lows); // Соединяем данную матрицу с единичной

double** Gauss_method(double** Matrix_Big, double** Matrix, int rows, int lows); // Метод Гаусса

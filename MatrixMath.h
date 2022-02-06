#ifndef UNTITLED1_MATRIXMATH_H
#define UNTITLED1_MATRIXMATH_H

bool isSimple(int N); //Функция проверки числа на простоту
//void Transpose(int matrix[M][M]); //Функция транспонирования матрицы
//void MatrixMul(int matrix[M][M], int mul); //Функция умножения матрицы на число
//void MatrixAdd(int matrixA[M][M], int matrixB[M][M]); //Функция суммы матриц

int** Transpose(int ** matrix, int h, int w);
int** MatrixMul(int ** arr, int height, int width, int mul);
int** MatrixAdd(int ** matrixA, int ** matrixB, int h, int w);
#endif //UNTITLED1_MATRIXMATH_H

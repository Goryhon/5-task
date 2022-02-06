#include <cmath>
#include "MatrixMath.h"
using namespace std;

bool isSimple(int N)
{
    for (int i = 2; i <= sqrt(N); i++)
        if (N % i == 0)
            return false;
    if ((N == 0) || (N == 1))
        return false;
    return true;
}

//void Transpose(int matrix[M][M])
//{
//    int t;
//    for (int i = 0; i < M; ++i)
//    {
//        for (int j = i; j < M; ++j)
//        {
//            t = matrix[i][j];
//            matrix[i][j] = matrix[j][i];
//            matrix[j][i] = t;
//        }
//    }
//}
//
//void MatrixMul(int matrix[M][M], int mul){
//	for(int i = 0; i < M; i++){
//		for(int j = 0; j < M; j++){
//			matrix[i][j] *= mul;
//		}
//	}
//}
//
//void MatrixAdd(int matrixA[M][M], int matrixB[M][M]){
//	for(int i = 0; i < M; i++){
//		for(int j = 0; j < M; j++){
//			matrixA[i][j] += matrixB[i][j];
//		}
//	}
//}

int** Transpose(int** matrix, int h, int w){
	if(h <= 0 || w <= 0)
		return NULL;

	int **to_ret = new int*[w];
	for(int i = 0; i < w; i++) {
		to_ret[i] = new int[h];
		for(int j = 0; j < h; j++){
			to_ret[i][j] = matrix[j][i];
		}
	}
	return to_ret;
}

int** MatrixMul(int ** arr, int h, int w, int mul){

	if(h <= 0 || w <= 0)
		return NULL;

	int** to_ret = new int*[h];
	for(int i = 0; i < h; i++){
		to_ret[i] = new int[w];
		for(int j = 0; j < w; j++){
			to_ret[i][j] = arr[i][j] * mul;
		}
	}
	return to_ret;
}

int** MatrixAdd(int **matrixA, int **matrixB, int h, int w){

	if(h <= 0 || w <= 0)
		return NULL;

	int **to_ret = new int*[h];
	for(int i = 0; i < h; i++){
		to_ret[i] = new int[w];
		for(int j = 0; j < w; j++){
			to_ret[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
	return  to_ret;
}
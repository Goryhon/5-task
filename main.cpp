#include <iostream>
#include <cmath>
#include "MatrixMath.h"
#include "MatrixConsolePrint.h"



using namespace std;

int main() {

	int h = 1,w = 5;

	int **arr = new int*[h];
	for(int i = 0; i < h; i++){
		arr[i] = new int[w];
		for(int j = 0; j < w; j++){
			arr[i][j] = j*i;
		}
	}

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}

	cout<<endl;
	int** arr1 = MatrixMul(arr,h,w,3);

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout<<arr1[i][j]<<' ';
		}
		cout<<endl;
	}

	cout<<endl;

	int** arr2 = MatrixAdd(arr,arr1,h,w);

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout<<arr2[i][j]<<' ';
		}
		cout<<endl;
	}

	cout<<endl;
	int **arr3 = Transpose(arr2, h,w);

	for(int i = 0; i < w; i++){
		for(int j = 0; j < h; j++){
			cout<<arr3[i][j]<<' ';
		}
		cout<<endl;
	}
}


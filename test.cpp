#include <iostream>
#include "gtest/gtest.h"
#include "MatrixMath.h"
#include "MatrixConsolePrint.h"

namespace TESTS{

    TEST(isSimpleTest, SimpleNumber) {
		EXPECT_TRUE(isSimple(2));
		EXPECT_TRUE(isSimple(3));
		EXPECT_TRUE(isSimple(5));
		EXPECT_TRUE(isSimple(7));
		EXPECT_TRUE(isSimple(2147483647));
	}

	TEST(isSimpleTest, NonSimpleNumber) {
		EXPECT_FALSE(isSimple(0));
		EXPECT_FALSE(isSimple(1));
		EXPECT_FALSE(isSimple(4));
		EXPECT_FALSE(isSimple(6));
		EXPECT_FALSE(isSimple(2147483646));
	}

	TEST(TransposeTest, SimplTest) {
		int arr[4][5] = {
				{-8, -7, -6, 5, -3},
				{0, -7, 7, -9, -4},
				{-1, 10, -8, -15, -5},
				{6, -4, -2, -5, -3}
		};

		int **input = new int*[4];
		for(int i = 0; i<4; i++){
			input[i] = new int[5];
			for(int j = 0; j < 5;j++){
				input[i][j] = arr[i][j];
			}
		}

		int answer[5][4] = {
				{-8, 0, -1, 6},
				{-7, -7, 10, -4},
				{-6, 7, -8, -2},
				{5, -9, -15, -5},
				{-3, -4, -5, -3}};

		int ** result = Transpose(input,4,5);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				EXPECT_EQ(result[i][j], answer[i][j]);
			}
		}
	}
    TEST(TransposeTest, NULL) {
        int **arr = new int*[4];
        for(int i = 0; i < 4; i++){
            arr[i] = new int[2];
            for(int j = 0; j < 2; j++){
                arr[i][j] = j*i;
            }
        }
        EXPECT_EQ(NULL, Transpose(NULL,4,5));
        EXPECT_EQ(NULL, Transpose(arr,0,2));
        EXPECT_EQ(NULL, Transpose(arr,4,0));
    }

	TEST(MatrixMul, GZero){
		int arr[5][5] = {
				{-12, -6, -6, -8, 3},
				{-8, -7, -6, 5, -3},
				{0, -7, 7, -9, -4},
				{-1, 10, -8, -15, -5},
				{6, -4, -2, -5, -3}};
		int mul = 2;

		int **input = new int*[5];
		for(int i = 0; i<5; i++){
			input[i] = new int[5];
			for(int j = 0; j < 5;j++){
				input[i][j] = arr[i][j];
			}
		}

		int answer[5][5] = {
				{-24, -12, -12, -16, 6},
				{-16, -14, -12, 10, -6},
				{0, -14, 14, -18, -8},
				{-2, 20, -16, -30, -10},
				{12, -8, -4, -10, -6}};

		int** result = MatrixMul(input,5,5, mul);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				EXPECT_EQ(result[i][j], answer[i][j]);
			}
		}
	}

	TEST(MatrixMul, LZero){
		int arr[5][5] = {
				{-12, -6, -6, -8, 3},
				{-8, -7, -6, 5, -3},
				{0, -7, 7, -9, -4},
				{-1, 10, -8, -15, -5},
				{6, -4, -2, -5, -3}};
		int mul = -2;

		int **input = new int*[5];
		for(int i = 0; i<5; i++){
			input[i] = new int[5];
			for(int j = 0; j < 5;j++){
				input[i][j] = arr[i][j];
			}
		}

		int answer[5][5] = {
				{24, 12, 12, 16, -6},
				{16, 14, 12, -10, 6},
				{0, 14, -14, 18, 8},
				{2, -20, 16, 30, 10},
				{-12, 8, 4, 10, 6}};
		int **result = MatrixMul(input,5,5, mul);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				EXPECT_EQ(result[i][j], answer[i][j]);
			}
		}
	}

	TEST(MatrixMul, Zero){
		int arr[5][5] = {
				{-12, -6, -6, -8, 3},
				{-8, -7, -6, 5, -3},
				{0, -7, 7, -9, -4},
				{-1, 10, -8, -15, -5},
				{6, -4, -2, -5, -3}};
		int mul = 0;

		int **input = new int*[5];
		for(int i = 0; i<5; i++){
			input[i] = new int[5];
			for(int j = 0; j < 5;j++){
				input[i][j] = arr[i][j];
			}
		}

		int answer[5][5] = {
				{0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0}};
		int **result = MatrixMul(input,5,5, mul);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				EXPECT_EQ(result[i][j], answer[i][j]);
			}
		}
	}

    TEST(MatrixMul, NULL) {
        int **arr = new int*[4];
        for(int i = 0; i < 4; i++){
            arr[i] = new int[2];
            for(int j = 0; j < 2; j++){
                arr[i][j] = j*i;
            }
        }
        EXPECT_EQ(NULL, MatrixMul(NULL,4,5,3));
        EXPECT_EQ(NULL, MatrixMul(arr,0,2,3));
        EXPECT_EQ(NULL, MatrixMul(arr,4,0,3));
    }

	TEST(MatrixAdd, SimpleTest){
		int arrA[5][5] = {
				{-12, -6, -6, -8, 3},
				{-8, -7, -6, 5, -3},
				{0, -7, 7, -9, -4},
				{-1, 10, -8, -15, -5},
				{6, -4, -2, -5, -3}};

		int **inputA = new int*[5];
		for(int i = 0; i<5; i++){
			inputA[i] = new int[5];
			for(int j = 0; j < 5;j++){
				inputA[i][j] = arrA[i][j];
			}
		}

		int arrB[5][5] = {
				{1, 2, 3, 4, 5},
				{6, 7, 8, 9, 0},
				{0, -1, -2, -3, -4},
				{-5, -6, -7, -8, -9},
				{6, 4, 3, 2, 1}};

		int **inputB = new int*[5];
		for(int i = 0; i<5; i++){
			inputB[i] = new int[5];
			for(int j = 0; j < 5;j++){
				inputB[i][j] = arrB[i][j];
			}
		}

		int answer[5][5] = {
				{-11, -4, -3, -4, 8},
				{-2, 0, 2, 14, -3},
				{0, -8, 5, -12, -8},
				{-6, 4, -15, -23, -14},
				{12, 0, 1, -3, -2}};
		int **result = MatrixAdd(inputA, inputB,5,5);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				EXPECT_EQ(result[i][j], answer[i][j]);
			}
		}
	}

    TEST(MatrixAdd, ZERO){
        int arrA[5][5] = {
                {-12, -6, -6, -8, 3},
                {-8, -7, -6, 5, -3},
                {0, -7, 7, -9, -4},
                {-1, 10, -8, -15, -5},
                {6, -4, -2, -5, -3}};

        int **inputA = new int*[5];
        for(int i = 0; i<5; i++){
            inputA[i] = new int[5];
            for(int j = 0; j < 5;j++){
                inputA[i][j] = arrA[i][j];
            }
        }

        int **inputB = new int*[5];
        for(int i = 0; i<5; i++){
            inputB[i] = new int[5];
            for(int j = 0; j < 5;j++){
                inputB[i][j] = 0 ;
            }
        }

        int answer[5][5] = {
                {-12, -6, -6, -8, 3},
                {-8, -7, -6, 5, -3},
                {0, -7, 7, -9, -4},
                {-1, 10, -8, -15, -5},
                {6, -4, -2, -5, -3}};
        int **result = MatrixAdd(inputA, inputB,5,5);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                EXPECT_EQ(result[i][j], answer[i][j]);
            }
        }
    }

    TEST(MatrixAdd, NULL) {
        int **arr = new int*[4];
        for(int i = 0; i < 4; i++){
            arr[i] = new int[2];
            for(int j = 0; j < 2; j++){
                arr[i][j] = j*i;
            }
        }
        EXPECT_EQ(NULL, MatrixAdd(arr,NULL,4,5));
        EXPECT_EQ(NULL, MatrixAdd(NULL,arr,4,5));
        EXPECT_EQ(NULL, MatrixAdd(arr,arr,0,2));
        EXPECT_EQ(NULL, MatrixAdd(arr,arr,4,0));
    }
}

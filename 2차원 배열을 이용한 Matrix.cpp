//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//// ���� 2 : 3x3 ����� ǥ���ϴ� struct Matrix 3x3
//typedef struct Matrix3x3 {
//	int matrix[3][3];
//	
//	void setMatrix(int mat[3][3]) {
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				matrix[i][j] = mat[i][j];
//			}
//		}
//	}
//	// ���� 3 : ���� ������ ����ϴ� ��� �Լ�
//	void printMatrix() {
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				cout << matrix[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//	// ���� 4 : Ư����ҿ� ������ �� �ִ� �Լ�
//	void at(int i, int j) {
//		cout << matrix[i][j] << endl;
//	}
//	// ���� 5 : �� ���� ���ڷ� �޾� ����� ���� �����ϴ� �Լ�
//	void add(int arr1[][3], int arr2[][3], int arr3[][3]) {
//			for (int i = 0; i < 3; i++) {
//				for (int j = 0; j < 3; j++) {
//					arr3[i][j] = arr1[i][j] + arr2[i][j];
//				}
//			}
//	}
//	// ���� 6 : ����� ������ �����ϴ� �Լ�
//	void mul(int arr1[][3], int arr2[][3], int arr3[][3]) {
//		for (int i = 0; i < 2; i++)
//		{
//			for (int j = 0; j < 2; j++)
//			{
//				int cum = 0;
//				for (int k = 0; k < 2; k++)
//				{
//					cum += arr1[i][k] * arr2[k][j];
//				}
//
//				arr3[i][j] = cum;
//			}
//		}
//	}
//	// ���� 7 : ����� �Ǻ����� ���ϴ� �Լ�
//	int det(int arr[][3]) {
//		int d = arr[0][0] * (arr[1][1] * arr[2][2] - arr[2][1] * arr[1][2])
//			- arr[0][1] * (arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0])
//			+ arr[0][2] * (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0]);
//		return d;
//	}
//	// ���� 8 : ����� Trace�� �����ϴ� �Լ�
//	int trace(int arr[][3]) {
//		for (int i = 0; i < 2; i++) {
//			for (int j = 0; j < 2; j++) {
//				int sum = arr[i][j];
//				
//				return sum;
//			}
//		}
//		
//	}
//} Mat;
//
//int main() {
//	int matrix1[3][3] = { {1,2,3}
//	,{4,5,6}
//	,{7,8,9}
//	};
//	int matrix2[3][3] = { {1,0,0},
//	{4,5,6},
//	{7,8,9}
//	};
//	int matrix3[3][3];
//	
//	Mat a;
//	a.setMatrix(matrix1);
//	a.printMatrix();
//	a.det(matrix1); // ���� 7 : A.det()�� �����ϴ� �Լ�
//
//	Mat b;
//	b.setMatrix(matrix2);
//
//	Mat c;
//	c.setMatrix(matrix3);
//	// ���� 9 : (AB).Trace()�� (AB).Det()�� �����ϴ� �Լ�
//	cout << c.det(matrix3) << endl;
//	cout << c.trace(matrix3) << endl;
//	return 0;
//}
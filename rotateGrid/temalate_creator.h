#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <ctime>
using namespace std;
int recursCount = 0;
//���������� ������������ ��������� ����� ���������� ������
void ResetArray(int** arr,int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
		for (int j = 0; j < size; j++) {
			arr[i][j] = 0;
		}
	}
}

//������ ������� ��� ���������� 8�8
//����� ������� 16 ������ ����� ����� �� �����������
void CryptoGrid(int** arr,int size) {
	int counter = 0;
	//��������� 1 ������� 4 �� 4 � ���� �� �����
	for (int i = 0; i<size / 2; i++) {
		for (int j = 0; j<size / 2; j++) {
			counter++;
			arr[i][j] = counter;
		}
	}
	counter = 0;
	//��������� 2 ������� 4 �� 4 � ���� � ����
	for (int j = 0; j<(size / 2); j++) {
		for (int i = 1; i <= size / 2; i++) {
			counter++;
			arr[size - i][j] = counter;
		}
	}

	counter = 0;

	for (int i = 1; i <= size / 2; i++) {
		for (int j = 1; j <= size / 2; j++) {
			counter++;
			arr[size - i][size - j] = counter;
		}
	}
	counter = 0;
	for (int j = 1; j <= size / 2; j++) {
		for (int i = 1; i <= size / 2; i++) {
			counter++;
			arr[i - 1][size - j] = counter;
		}
	}

}


void ShowGrid(int **arr,int size) {
	cout << endl << endl;
	for (int i = 0; i <size; i++) {
		for (int j = 0; j<size; j++) {
			cout << setw(5) <<arr[i][j]<<" ";
		}
		cout << endl << endl;
	}
}


void DellOther(int base_i, int base_j, int **arr,int size) {
	int curr = arr[base_i][base_j];
	for (int i = 0; i<size; i++) {
		for (int j = 0; j<size; j++) {
			if (arr[i][j] == curr) arr[i][j] = 0;
		}
	}
	arr[base_i][base_j] = curr;
}

void GeterateTable(int **arr,int size) {
	for (int i = 0; i < size*size; i++) {
		DellOther(rand() % size, rand() % size, arr,size);
	}
}

void CerateTemplate(int **arr,int size) {
	ResetArray(arr, size);
	CryptoGrid(arr,size);
	GeterateTable(arr, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == 0) arr[i][j] = 1;
			else if (arr[i][j] > 0)  arr[i][j] = 0;
		}
	}
	//ShowGrid(arr,size);
}

void DellTemplate(int **arr,int size) {
	for (int count = 0; count < size; count++)
		delete[]arr[count];
}

//������ ����� ������ � ������������ ��� ����� �� -90
void RotateArray(int **arr, int **rotated, int size) {
	for (int i = 0; i < size; i++) {
		rotated[i] = new int[size];
		for (int j = 0; j < size; j++) {
			rotated[i][j] = arr[i][j];
		}
	}

	int tmp;
	for (int i = 0; i<size / 2; i++) {
		for (int j = i; j<size - 1 - i; j++) {
			tmp = rotated[i][j];
			rotated[i][j] = rotated[j][size - 1 - i];
			rotated[j][size - 1 - i] = rotated[size - 1 - i][size - 1 - j];
			rotated[size - 1 - i][size - 1 - j] = rotated[size - 1 - j][i];
			rotated[size - 1 - j][i] = tmp;
		}
	}
}
void CreateRotatedCopy(int **arr, int **first, int ** second, int ** third, int size) {
	RotateArray(arr, first, size);
	RotateArray(first, second, size);
	RotateArray(second, third, size);
}
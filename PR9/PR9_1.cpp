#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<cstring>
#include<ctime>
/*
��������:������� ����� ���������, ���-21
������������ �9 ,������� �2
�������:�������� ������ ���������� "���������"
*/

using namespace std;

int main () {
	system ("chcp 1251");
	
	int arraySize;
	
	cout << "������� ���������� ��������� �������: " << endl;
	cin >> arraySize;
	
	int array[arraySize];
	
	cout << "���������� ������ �� " << arraySize << " ��������� �����:" << endl;
	for (int i = 0; i < arraySize; i++) {
		array[i] = rand()%100;
		cout << "array[" << i << "] = " << array[i] << endl;
	}
	
	for (int i = 0; i < arraySize - 1; i++) {
		for (int j = 0; j < arraySize - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	cout << "������� ���������� \"���������\":" << endl;
	for (int i = 0; i < arraySize; i++) {
		cout << "array[" << i << "] = " << array[i] << endl;
	}
	
	system("pause");	
	return 0;
}

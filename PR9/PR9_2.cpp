#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<cstring>
#include<ctime>
/*
��������:������� ����� ���������, ���-21
������������ �9 ,������� �2
�������:�������� �������
*/

using namespace std;

int main () {
	system ("chcp 1251");
	int arraySize;
	int min = 0;
	int buf = 0;
	

	cout << "������� ���-�� ��������� �������: " << endl;
	cin >> arraySize;
	int array[arraySize];
	
	for(int i=0;i<arraySize;i++){
		array[i] = rand()%20;
		cout << "array[" << i << "] = " << array[i] << endl;
	}
	for (int i = 0; i <arraySize; i++)
	{
		min = i; 		
		for (int j = i + 1; j <arraySize; j++)
			min = ( array[j] < array[min] ) ? j : min;
		if (i != min)
		{
			buf = array[i];
			array[i] = array[min];
			array[min] = buf;
		}
	}
	cout<<"C��������� \''�������''\:" << endl;
	for (int i = 0; i < arraySize; i++) 	
		cout << array[i] << " ";
	cout << endl;

	system("pause");	
	return 0;
}

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
/*
��������:������� ����� ���������,���-21
����:27.06.2022
������������ �6 , ������� �2
�������:��������� ���������, ������� ��������� ����������
������ �� n ��������� �����. �������� �� ���� ��� �����
�������: ���� �� ������ �����, � ������ �� ��������. ��������
n �������� � �������� �� 10 �� 50 ���������.
*/
using namespace std;
int main () {
	system ("chcp 1251");
	
	int n,i,c,e;
		
	cout<<""<< endl;
	cin >> n;
	
	int array[n], array_2[n], array_3[n];
	
	cout <<"������������� ������ �� " <<n<< " ��������� �����:"<<endl;
	for (i=0; i<n; i++) {
		array[i] = rand() % 50000000+10000000;
		cout<<"array[" <<i<<"] =" <<array[i]<<endl;
	}
	for (i=0; i<n; i++) {
		if (array[i]%2==0){
		array_2[i] = array[i];
		cout<<"array_2[" <<i<<"] =" <<array_2[i]<<endl;
		}
		else{
			array_3[i]=array[i];
			cout<<"array_3[" <<i<<"] =" <<array_3[i]<<endl;
		}	
	}
	system ("pause");
	return 0;
	
}

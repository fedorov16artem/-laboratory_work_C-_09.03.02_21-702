#include <iostream>

/*
��������:������� ����� ���������,���-21
������������ �8, ������� 2
�������:����������� �������� � ��������� ����������� ���������
������. � �������� �������� ������ ������������ ������ ������, ��
������� ���������� �������� �����. �������� ������ � �����.
*/
using namespace std;
 

int Namestas(int size) { 
    size--;
    if (size < 0) {
        return -1;
    }
    return Namestas( size );
 
}
main(){
	system("chcp 1251");
	int size;
	cin>> size;
	string *a = new string[size];
	for(int i=0;i<size;i++){
		cin>> a[i];
	}
	cout<<"�������� �����: ";
		for(int i=0;i<size;i++){
			cout<< a[i]<< " ";
		}
	
	cout<<endl;
	string query;
	cout << "������� �����: ";
	cin >> query;
	for(int i=0;i<size;i++){
		if (a[i]==query) cout<<query<<" � ������- "<<i;
	
	}
	
	


	
	
	
}

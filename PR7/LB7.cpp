#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<cstring>
#include<ctime>
/*
Выполнил:Федоров Артем Андреевич,зит-21
Лабараторная №7, Вариант 2
Задание:Разработать алгоритм и программу ускоренного линейного
поиска. В качестве исходных данных использовать строку текста, из
которой необходимо выделить слова. Аргумент поиска – слово.
*/
using namespace std;

main(){
	system("chcp 1251");
	int size;
	cin>> size;
	string *a = new string[size];
	srand(time(NULL));
	
	for(int i=0;i<size;i++){
		cin>> a[i];
	}
	cout<<"Выберите слово: ";
		for(int i=0;i<size;i++){
			cout<< a[i]<< " ";
		}
	
	cout<<endl;
	string query;
	cout << "Ввиде слово: ";
	cin >> query;
	for(int i=0;i<size;i++){
		if (a[i]==query) cout<<query<<" В строке - "<<i;
	
	}
	
	


	
	
	
}

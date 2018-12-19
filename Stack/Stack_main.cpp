#include <iostream>
#include <locale.h>
#include "Stack.h"

using namespace std;

int  main (){

	setlocale(LC_ALL, "Russian");

	TStack<int> A(8);
	cout << "IsEmpty:" << A.IsEmpty() << endl;
	A.Put(7);
	A.Put(4);
	cout <<"IsFull:"<< A.IsFull()<<endl;
	cout <<"Get_1:"<< A.Get()<<endl;
	cout << "IsEmpty:" << A.IsEmpty() << endl;
	cout << "Get_1:" << A.Get() << endl;
	cout << "IsEmpty:" << A.IsEmpty() << endl;

	return 0;
}
#include <iostream>
#include <locale.h>
#include "Stack.h"
#include "ExceptionLib.h"

using namespace std;

int  main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите размер стека: ";
	int len;
	cin >> len;

	try
	{
		TStack<int> St(len);
		for (int i = 0; i < len; i++)
			St.Put(i);

		cout << "\nСтек выбранной вами длины: \n";
		St.PrintStack();

		TStack<int> CopySt(St);
		cout << "\n\nСкопированный стек: \n";
		CopySt.PrintStack();

		if (CopySt == St)
			cout << "\n\nСкопированный и введенный изначально стеки равны";

		cout << "\n\nВозьмем элемент из стека: " << St.Get();

		cout << "\n\nТеперь у нас есть стек: \n";
		St.PrintStack();

		if (CopySt != St)
			cout << "\n\nИ теперь стек изначальный и скопированный различны";
	}

	catch (MyException exp)
	{
		exp.Print();
	}
	return 0;
}

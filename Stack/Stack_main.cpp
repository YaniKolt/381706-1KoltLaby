#include <iostream>
#include <locale.h>
#include "Stack.h"
#include "ExceptionLib.h"

using namespace std;

int  main()
{
	setlocale(LC_ALL, "Russian");

	cout << "������� ������ �����: ";
	int len;
	cin >> len;

	try
	{
		TStack<int> St(len);
		for (int i = 0; i < len; i++)
			St.Put(i);

		cout << "\n���� ��������� ���� �����: \n";
		St.PrintStack();

		TStack<int> CopySt(St);
		cout << "\n\n������������� ����: \n";
		CopySt.PrintStack();

		if (CopySt == St)
			cout << "\n\n������������� � ��������� ���������� ����� �����";

		cout << "\n\n������� ������� �� �����: " << St.Get();

		cout << "\n\n������ � ��� ���� ����: \n";
		St.PrintStack();

		if (CopySt != St)
			cout << "\n\n� ������ ���� ����������� � ������������� ��������";
	}

	catch (MyException exp)
	{
		exp.Print();
	}
	return 0;
}

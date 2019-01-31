#include "ArrList.h"

int main()
{
	try
	{
		setlocale(LC_ALL, "Russian");

		cout << "Введите размер списка: ";
		int l;
		cin >> l;
		cout << endl;
		TArrList<int> aList(l);
		int i;
		for (i = 1; i <= l / 3; i++)
		{
			cout << "Положить в конец:" << i << endl;
			aList.PutEnd(i);
		}
		for (i; i <= 2 * (l / 3); i++)
		{
			cout << "Положить в начало: " << i << endl;
			aList.PutStart(i);
		}
		for (i; i <= l; i++)
		{
			cout << "Положить в конец:" << i << endl;
			aList.PutEnd(i);
		}
		cout << "\n\nСоздать список" << endl;
		aList.Print();
		cout << "\n\n";


		for (i = 1; i <= l / 3; i++)
			cout << "Взять из конца:" << aList.GetEnd() << endl;
		for (i; i <= 2 * (l / 3); i++)
			cout << "Взять из начала: " << aList.GetStart() << endl;
		for (i; i <= l; i++)
			cout << "Взять из конца:" << aList.GetEnd() << endl;
	}
	catch (MyException exc)
	{
		exc.Print();
	}

  return 0;
}

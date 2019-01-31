#include "List.h"

int main()
{
  try
  {
		setlocale(LC_ALL, "Russian");
    TList<int> list;
		cout << "Введите желаемое количество элементов списка: ";
		int l;
		cin >> l;
		cout << endl;
		int i;
		for (i = 1; i <= l / 3; i++)
		{
			cout << "Положить в конец:" << i << endl;
			list.PutEnd(i);
		}
		for (i; i <= 2 * (l / 3); i++)
		{
			cout << "Положить в начало: " << i << endl;
			list.PutStart(i);
		}
		for (i; i <= l; i++)
		{
			cout << "Положить в конец:" << i << endl;
			list.PutEnd(i);
		}
    /*cout << "Введите количество элементов начала списка: ";
    int st, end;
    cin >> st;
    for (int i = 0; i <= st-1; i++)
      list.PutBegin(i);
    cout << "\nВведите количество элементов конца списка: ";
    cin >> end;
    for (int i = 0; i <= end-1; i++)
      list.PutEnd(i);*/

    cout << "\n\nСозданный список: \n";
    list.Print();

    cout << "\n\nЭлемент в верхней части: " << list.GetStart();
    cout << "\nЭлемент в нижней части: " << list.GetEnd();

    cout << "\n\nСписок теперь: \n";
    list.Print();
  }

  catch (MyException exp)
  {
    exp.Print();
  }

  return 0;
}


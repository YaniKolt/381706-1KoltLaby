#include "StackList.h"

int main()
{
	setlocale(LC_ALL, "Russian");

  cout << "Введите размер стека: ";
  int lengt;
  cin >> lengt;

  try
  {
    TStackList<int> stlst(lengt);

    for (int i = 0; i < lengt; i++)
    {
      stlst.Put(i);
    }

		if (stlst.IsFull())
		{
			cout << "\nСтек заданной длины: \n";
			stlst.PrintStLst();
			cout << "\nСтек полон.\n";
		}
  
		cout << "\nПервый элемент в стеке: " << stlst.Get() << endl;
		cout << "Стек сейчас:\n";
		stlst.PrintStLst();
		cout << "\nТекущая длина = " << stlst.GetLeng() << "\nМаксимальная длина = " << stlst.GetMaxLeng() << endl;

		cout << "\nОставшийся стек:\n";
		int j = 1;

    while (!stlst.IsEmpty())
     cout << "Элемент номер " << j++ << " : " << stlst.Get() << endl;
    cout << "Стек пуст.\n";
  }

  catch (MyException exc)
  {
    exc.Print();
  }
  return 0;
}
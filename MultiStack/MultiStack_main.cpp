#include "MultiStack.h"
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

  /*cout << "Создадим свой мультистек\n";*/
  int tmp = 1;
	int numstack, data;

  try
  {
		//cout << "Пусть наш мультистек имеет общую длину 10 и состоит из 5 стеков.\n";
		cout << "Введите общее количество элементов:\n";
		int co, st;
		cin >> co;
		cout << "Введите количество стеков:\n";
		cin >> st;
    TMStack<int> mst(st, co);

		cout << "Заполним мультистек:\n";

    for (int i = 0; i < st; i++)
      for (int j = 0; j < co/st; j++)
      {
        mst.Set(i, tmp);
        cout <<"Число [" << tmp << "] кладем в стек под номером  " << i + 1 << endl;
				tmp++;
      }

    mst.PrintMStack();
    cout << "\n\n";

		cout << "Введите номер стека, из которого хотите взять элемент: ";
		cin >> numstack;

		cout << "\nИз стека под номером [" << numstack << "] взят элемент " << mst.Get(numstack - 1) << endl;

		mst.PrintMStack();

		cout << "\nВведите номер стека в который хотите добавить элемент(если стек уже заполнен, то мультистек изменится): ";
		cin >> numstack;

		cout << "Введите элемент, который хотите добавить: ";
		cin >> data;

		mst.Set(numstack-1, data);

    mst.PrintMStack();

  }

  catch (MyException exс)
  {
    exс.Print();
  }

  return 0;
}
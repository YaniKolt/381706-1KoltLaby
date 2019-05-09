#include <iostream>
#include"Queue.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int len;
	cout << "Введите длину очереди\n";
	cin >> len;
	try
	{
		TQueue<int> Qu(len);
		for (int i = 0; i < len; i++)
		{
			Qu.Put(i);
			cout << "В очередь введено " << i << endl;
		}

		while (!Qu.IsEmpty())
		{
			len = Qu.Get();
			cout << "В очереди лежит " << len << endl;
		}
	}
	catch (MyException exp)
	{
		exp.Print();
	}
	return 0;
}

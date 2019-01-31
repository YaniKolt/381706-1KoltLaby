#include "ArrList.h"

int main()
{
	try
	{
		setlocale(LC_ALL, "Russian");

		cout << "������� ������ ������: ";
		int l;
		cin >> l;
		cout << endl;
		TArrList<int> aList(l);
		int i;
		for (i = 1; i <= l / 3; i++)
		{
			cout << "�������� � �����:" << i << endl;
			aList.PutEnd(i);
		}
		for (i; i <= 2 * (l / 3); i++)
		{
			cout << "�������� � ������: " << i << endl;
			aList.PutStart(i);
		}
		for (i; i <= l; i++)
		{
			cout << "�������� � �����:" << i << endl;
			aList.PutEnd(i);
		}
		cout << "\n\n������� ������" << endl;
		aList.Print();
		cout << "\n\n";


		for (i = 1; i <= l / 3; i++)
			cout << "����� �� �����:" << aList.GetEnd() << endl;
		for (i; i <= 2 * (l / 3); i++)
			cout << "����� �� ������: " << aList.GetStart() << endl;
		for (i; i <= l; i++)
			cout << "����� �� �����:" << aList.GetEnd() << endl;
	}
	catch (MyException exc)
	{
		exc.Print();
	}

  return 0;
}

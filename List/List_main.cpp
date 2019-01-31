#include "List.h"

int main()
{
  try
  {
		setlocale(LC_ALL, "Russian");
    TList<int> list;
		cout << "������� �������� ���������� ��������� ������: ";
		int l;
		cin >> l;
		cout << endl;
		int i;
		for (i = 1; i <= l / 3; i++)
		{
			cout << "�������� � �����:" << i << endl;
			list.PutEnd(i);
		}
		for (i; i <= 2 * (l / 3); i++)
		{
			cout << "�������� � ������: " << i << endl;
			list.PutStart(i);
		}
		for (i; i <= l; i++)
		{
			cout << "�������� � �����:" << i << endl;
			list.PutEnd(i);
		}
    /*cout << "������� ���������� ��������� ������ ������: ";
    int st, end;
    cin >> st;
    for (int i = 0; i <= st-1; i++)
      list.PutBegin(i);
    cout << "\n������� ���������� ��������� ����� ������: ";
    cin >> end;
    for (int i = 0; i <= end-1; i++)
      list.PutEnd(i);*/

    cout << "\n\n��������� ������: \n";
    list.Print();

    cout << "\n\n������� � ������� �����: " << list.GetStart();
    cout << "\n������� � ������ �����: " << list.GetEnd();

    cout << "\n\n������ ������: \n";
    list.Print();
  }

  catch (MyException exp)
  {
    exp.Print();
  }

  return 0;
}


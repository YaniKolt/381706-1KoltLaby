#include "SortTable.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

  TSortTable<int> table(7);
  TSortElem<int> elem;

	table.Put("�", 0);
	table.Put("��", 1);
	table.Put("���", 2);
	table.Put("����", 3);
	table.Put("�����", 5);
	table.Put("������", 8);
	cout << "����� �������� � ������ : \"����\"\n";
	elem = table.Search("����");
	cout << "����: " << elem.GetKey() << "  ������: " << elem.GetData() << "\n";
	cout << "������� ������� � ������: \"����\"\n";
	table.Del("����");
	cout << "����� �������� � ������: \"����\"\n";
	elem = table.Search("����");
	cout << "����: " << elem.GetKey() << "  ������: " << elem.GetData() << "\n";

  return 0;
}
 
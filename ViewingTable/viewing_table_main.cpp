#include <iostream>
#include "ViewingTable.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	TTable<int> table(6);
//	TTable<int> table(74);
	TElem<int> elem;
	table.Put("�", 1);
	table.Put("��", 1);
	table.Put("���", 2);
	table.Put("����", 3);
	table.Put("�����", 5);
	table.Put("������", 8);
	cout << "����� �������� � ������ : \"������\"\n";
	elem = table.Search("������");
	cout << "����: " << elem.GetKey() << "  ������: " << elem.GetData() << "\n";
	cout << "������� ������� � ������: \"������\"\n";
	table.Del("������");
	cout << "����� �������� � ������: \"������\"\n";
	elem = table.Search("������");
	cout << "����: " << elem.GetKey() << "  ������: " << elem.GetData() << "\n";
	

	return 0;
}
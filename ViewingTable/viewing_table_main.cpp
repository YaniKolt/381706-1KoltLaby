#include <iostream>
#include "ViewingTable.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	TTable<int> table(6);
//	TTable<int> table(74);
	TElem<int> elem;
	table.Put("к", 1);
	table.Put("кл", 1);
	table.Put("клю", 2);
	table.Put("ключ", 3);
	table.Put("ключи", 5);
	table.Put("ключик", 8);
	cout << "Поиск элемента с ключом : \"ключик\"\n";
	elem = table.Search("ключик");
	cout << "Ключ: " << elem.GetKey() << "  Данные: " << elem.GetData() << "\n";
	cout << "Удалить элемент с ключом: \"ключик\"\n";
	table.Del("ключик");
	cout << "Поиск элемента с ключом: \"ключик\"\n";
	elem = table.Search("ключик");
	cout << "Ключ: " << elem.GetKey() << "  Данные: " << elem.GetData() << "\n";
	

	return 0;
}
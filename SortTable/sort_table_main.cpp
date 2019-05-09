#include "SortTable.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

  TSortTable<int> table(7);
  TSortElem<int> elem;

	table.Put("к", 0);
	table.Put("кл", 1);
	table.Put("клю", 2);
	table.Put("ключ", 3);
	table.Put("ключи", 5);
	table.Put("ключик", 8);
	cout << "Поиск элемента с ключом : \"ключ\"\n";
	elem = table.Search("ключ");
	cout << "Ключ: " << elem.GetKey() << "  Данные: " << elem.GetData() << "\n";
	cout << "Удалить элемент с ключом: \"ключ\"\n";
	table.Del("ключ");
	cout << "Поиск элемента с ключом: \"ключ\"\n";
	elem = table.Search("ключ");
	cout << "Ключ: " << elem.GetKey() << "  Данные: " << elem.GetData() << "\n";

  return 0;
}
 
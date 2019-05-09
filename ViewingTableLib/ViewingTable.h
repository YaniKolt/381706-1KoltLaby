#include "TableElem.h"

template <class T>
class TTable
{
protected:
	TElem<T> notFound;
	TElem<T> *mas;
	int length;
	int count;
public:
	TTable(int _size = 10);                  //Конструктор-инициализатор  
	TTable(TTable &elem);                    //Конструктор копирования


	void Put(string _key, T _data);          //Вставить элемент в таблицу
	void Del(string _key);                   //Удалить элемент из таблицы

  void SetLeng(int _leng);                 //Задать размер
  void SetCount(int _count);               //Задать количество

  int GetSize();                           //Получить размер
	int GetCount();                          //Получить количество

	TElem<T>& Search(string _key);           //Поиск элемента по ключу
	T& operator[](string _key);              //Доступ к элементу по ключу
	
};

template <class T>
TTable<T>::TTable(int _leng)
{
	if (_leng < 0)
		throw MyException("Error length\n");
	else if (_leng == 0)
	{
		length = 0;
		count = 0;
		notFound.SetKey("No elem");
		notFound.SetData(-1);
		mas = NULL;
	}
	else
	{
		length = _leng;
		count = 0;
		notFound.SetKey("No elem");
		notFound.SetData(-1);
		mas = new TElem<T>[length];
	}
}

template <class T>
TTable<T>::TTable(TTable &elem)
{
	length = elem.length;
	count = elem.count;
	mas = new TElem<T>[length];
	for (int i = 0; i < length; i++)
		mas[i] = elem.mas[i];
}

template <class T>
void TTable<T>::Put(string _key, T _data)
{
	if (length == count)
		throw MyException("Error: table is full\n");
	else
	{
		mas[count].SetKey(_key);
		mas[count].SetData(_data);
		count++;
	}
}

template <class T>
void TTable<T>::Del(string _key)
{
	if (count == 0)
		throw MyException("Error: table is empty\n");
	else
	{
		TElem<T>& tmp = Search(_key);
		if (!(tmp == notFound))
			tmp = notFound;
	}
}

template <class T>
TElem<T>& TTable<T>::Search(string _key)
{
	for (int i = 0; i < count; i++)
		if (_key == mas[i].GetKey())
			return mas[i];
	return notFound;
}

template <class T>
T& TTable<T>::operator[](string _key)
{
	TElem<T>& tmp = Search(_key);
	if (tmp == notFound)
	{
		Put(_key, 0);
		return mas[count - 1].GetDataAddress();
	}
	return tmp.GetDataAddress();
}

template <class T>
void TTable<T>::SetLeng(int _leng)
{
	length = _leng;
}

template <class T>
int TTable<T>::GetSize()
{
	return length;
}

template <class T>
void TTable<T>::SetCount(int _count)
{
	count = _count;
}

template <class T>
int TTable<T>::GetCount()
{
	return count;
}
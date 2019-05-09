#pragma once
#include "SortTableElem.h"

template<class T>
class TSortTable
{
protected:
  TSortElem<T> notFound; 
  TSortElem<T>* mas;
  int leng;
  int count;
public:
  TSortTable(string* _keys, T* _data, int _leng);      //Конструктор инициализатор
  TSortTable(int _leng = 10);                          //Конструктор по умолчанию
  TSortTable(TSortTable<T> &elem);                     //Конструктор копирования
  
  void SetLeng(int _leng);                             //Задать размер
  void SetCount(int _count);                           //Задать количество

  int GetLeng();                                       //Получить размер
  int GetCount();                                      //Получить количество

	int Put(string _key, T _data);                       //Вставить элемент в таблицу
  void Del(string _key);                               //Удалить элемент из таблицы
  TSortElem<T>& Search(string _key);                   //Поиск элемента по ключу
  T& operator[](string _key);   
	void Resize(int _leng);                    
};

template<class T>
TSortTable<T>::TSortTable(string* _keys, T* _data, int _leng)
{
  if (_leng <= 0)
    throw MyException("Error leng\n");
  else
  {
    leng = _leng;
    count = 0;
    mas = new TSortElem<T>[leng];
    for (int i = 0; i < leng; i++)
      Put(_keys[i], _data[i]);
  }
}

template<class T>
TSortTable<T>::TSortTable(int _leng)
{
  if (_leng <= 0)
    throw MyException("Error leng\n");
  else if (_leng == 0)
  {
    leng = 0;
    count = 0;
    notFound.SetKey("No elem");
    notFound.SetData(-1);
    mas = NULL;
  }
  else
  {
    leng = _leng;
    count = 0;
    notFound.SetKey("No elem");
    notFound.SetData(-1);
    mas = new TSortElem<T>[leng];
  }
}

template<class T>
TSortTable<T>::TSortTable(TSortTable<T> &elem)
{
  leng = elem.leng;
  count = elem.count;
  mas = new TSortElem<T>[leng];
  for (int i = 0; i < leng; i++)
    mas[i] = elem.mas[i];
}

template<class T>
int TSortTable<T>::Put(string _key, T _data)
{
  if (leng <= count)
    Resize(count * 2);
  if (count == 0)
  {
    TSortElem<T> tmp(_key, _data);
    mas[0] = tmp;
    count++;
    return 0;
  }
  int right = count;
  int left = 0;
  int cur = count / 2;
  while (left < right)
  {
    if (mas[cur].GetKey() > _key)
    {
      right = cur-1;
      cur = ((left + right) / 2);
    }
    else if (mas[cur].GetKey() < _key)
    {
      left = cur+1;
      cur = ((left + right) / 2);
    }
    else
    {
      throw MyException("Error key\n");
    }
  }
  for (int i = cur; i < count; i++)
    mas[i + 1] = mas[i];
  TSortElem<T> tmp(_key, _data);
  mas[cur] = tmp;
  count++;
  return cur;
}

template<class T>
void TSortTable<T>::Del(string _key)
{
  int right = count;
  int left = 0;
  int cur = count / 2;
  while (left < right)
  {
    if (mas[cur].GetKey() > _key)
    {
      right = cur-1;
      cur = ((left + right) / 2);
    }
    else if (mas[cur].GetKey() < _key)
    {
      left = cur+1;
      cur = ((left + right) / 2);
    }
    else
    {
      for (int i = cur; i < count-1; i++)
        mas[i] = mas[i + 1];
      count--;
    }
  }
}

template<class T>
TSortElem<T>& TSortTable<T>::Search(string _key)
{
  int right = count;
  int left = 0;
  int mid = count / 2;
  while (left<right)
  {
    if (mas[mid].GetKey() > _key)
    {
      right = mid;
      mid = ((left + right) / 2);
    }
    else if (mas[mid].GetKey() < _key)
    {
      left = mid+1;
      mid = ((left + right) / 2);
    }
    else
      return mas[mid];
  }
  return notFound;
}

template<class T>
void TSortTable<T>::Resize(int _leng)
{
  if (_leng < leng)
    throw MyException("Error size\n");
  TSortElem<T>* newMas = new TSortElem<T>[_leng];
  for (int i = 0; i < leng; i++)
    newMas[i] = mas[i];
  delete[] mas;
  mas = newMas;
  leng = _leng;
}

template<class T>
T& TSortTable<T>::operator[](string _key)
{
  TSortElem<T>& tmp = Search(_key);
  if (tmp == notFound)
  {
    Put(_key, 0);
    return mas[count - 1].GetDataAddress();
  }
  return tmp.GetDataAddress();
}

template <class T>
void TSortTable<T>::SetLeng(int _leng)
{
  leng = _leng;
}

template <class T>
int TSortTable<T>::GetLeng()
{
  return leng;
}

template <class T>
void TSortTable<T>::SetCount(int _count)
{
  count = _count;
}

template <class T>
int TSortTable<T>::GetCount()
{
  return count;
}

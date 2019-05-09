#pragma once
#include <iostream>
#include "ExceptionLib.h"

template <class T>
class TSortElem
{
protected:
  string key;
  T data;
public:
  TSortElem(string _key = "", T _data = 0);          //Конструктор-инициализатор
  TSortElem(TSortElem<T> &elem);                     //Конструктор копирования

  void SetKey(string _key);                          //Задать ключ
  void SetData(T _data);                             //Задать данные

  string GetKey();                                   //Получить ключ
  T GetData();                                       //Получить данные
  T& GetDataAddress();                               //Получить адрес данных

  TSortElem<T>& operator=(TSortElem<T> &elem);       //Оператор присваивания
  bool operator==(TSortElem<T> &elem);               //Сравнение на равенство
  bool operator>(TSortElem<T> &elem);                //Сравнение
  bool operator<(TSortElem<T> &elem);                //Сравнение


};

template <class T>
TSortElem<T>::TSortElem(string _key, T _data)
{
  key = _key;
  data = _data;
}

template <class T>
TSortElem<T>::TSortElem(TSortElem<T> &elem)
{
  key = elem.key;
  data = elem.data;
}

template <class T>
TSortElem<T>& TSortElem<T>::operator=(TSortElem<T> &elem)
{
  if (this != &elem)
  {
    key = elem.key;
    data = elem.data;
  }
  return *this;
}

template <class T>
bool TSortElem<T>::operator==(TSortElem &elem)
{
  if (key != elem.key)
    return 0;
  if (data != elem.data)
    return 0;
  return 1;
}

template <class T>
bool TSortElem<T>::operator<(TSortElem &elem)
{
  if (key.compare(elem.key)<0)
    return 1;
  return 0;
}

template <class T>
bool TSortElem<T>::operator>(TSortElem &elem)
{
  if (key.compare(elem.key) > 0)
    return 1;
  return 0;
}

template <class T>
void TSortElem<T>::SetKey(string _key)
{
  key = _key;
}

template <class T>
string TSortElem<T>::GetKey()
{
  return key;
}

template <class T>
void TSortElem<T>::SetData(T _data)
{
  data = _data;
}

template <class T>
T TSortElem<T>::GetData()
{
  return data;
}

template <class T>
T& TSortElem<T>::GetDataAddress()
{
  return data;
}
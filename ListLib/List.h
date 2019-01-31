#pragma once 
#include "Elem.h"
#include "ExceptionLib.h"
#include <iostream>
using namespace std;

template <class T>
class TList
{
protected:
  TElem<T>* start;               //указатель на элемент в начале списка
  int count;                     //количество элементов в списке 

public:
  TList();                       //конструктор по умолчанию
  TList(TList<T> &list);         //конструктор копирования
  virtual ~TList();              //деструктор
  int GetLeng();                 //получить количество элементов в листе
  void Put(int _n, T elem);      //установть элемент на позицию n в списке
  T Get(int _n);                 //получить элемент из списка
  void PutStart(T elem);         //положить в начало 
  void PutEnd(T elem);           //положить в конец 
  T GetStart();                  //получить элемент в начале списка 
  T GetEnd();                    //получить элемент в конце списка 
  bool IsFull();                 //проверка на полноту 
  bool IsEmpty();                //проверка на пустоту 
  void Print();                  //Вывод
};

template <class T>
TList<T>::TList()
{
  start = 0;
  count = 0;
}

template <class T>
TList<T>::TList(TList<T> &L)
{
  count = L.count;
  TElem<T>* a = L.start;
  TElem<T>* b;
  if (L.start == 0)
    start = 0;
  else
  {
    start = new TElem<T>(*L.start);
    b = start;
    while (a->GetNext() != 0)
    {
      b->SetNext(new TElem<T>(*(a->GetNext())));
      a = a->GetNext();
      b = b->GetNext();
    }
  }
}

template <class T>
TList<T>::~TList()
{
  while (start != 0)
  {
    TElem<T>* temp = start;
    start = start->GetNext();
    delete temp;
  }
}

template<class T>
int TList<T>::GetLeng()
{
  return count;
}

template<class T>
void TList<T>::Put(int _n, T elem)
{
  if (this->IsFull())
    throw MyException("List is Full");
  if (_n < 1 || _n > count - 1)
    throw MyException("Incorrect index");
  else
  {
    int i = 0;
    TElem<T>* a = start;
    while (i != _n - 1)
    {
      a = a->GetNext();
      i++;
    }
    TElem<T>* temp = new TElem<T>(elem, a->GetNext());
    a->SetNext(temp);
    count++;
  }
}

template<class T>
T TList<T>::Get(int _n)
{
  if (this->IsEmpty())
    throw MyException("List is Empty");
  if (_n < 1 || _n > count - 1)
    throw MyException("Incorrect index");
  else
  {
    int i = 0;
    count--;
    TElem<T>* a = start;
    TElem<T>* b = start->GetNext();
    while (i != _n - 1)
    {
      a = b;
      b = b->GetNext();
      i++;
    }
    T temp = b->GetData();
    a->SetNext(b->GetNext());
    delete b;
    return temp;
  }
}

template <class T>
void TList<T>::PutStart(T A)
{
  if (this->IsFull())
    throw MyException("List is Full");
  if (start == 0)
  {
    TElem<T>* temp = new TElem<T>(A, 0);
    start = temp;
  }
  else
  {
    TElem<T>* temp = new TElem <T>(A, start);
    start = temp;
  }
  count++;
}

template <class T>
void TList<T>::PutEnd(T A)
{
  if (this->IsFull())
    throw MyException("List is Full");
  if (start != 0)
  {
    TElem<T>* a = start;
    while (a->GetNext() != 0)
      a = a->GetNext();
    a->SetNext(new TElem <T>(A, 0));
  }
  else
    start = new TElem<T>(A, 0);
  count++;
}

template <class T>
T TList<T>::GetStart()
{
  if (IsEmpty())
    throw MyException("List is Empty!");
  else
  {
    TElem<T>* a = start;
    T temp = start->TElem<T>::GetData();
    start = start->TElem<T>::GetNext();
    delete a;
    count--;
    return temp;
  }
}

template <class T>
T TList<T>::GetEnd()
{
  if (IsEmpty())
    throw MyException("List is Empty!");
  else
  {
    count--;
    TElem<T>* a = start;
    TElem<T>* b = start->GetNext();
    if (b == 0)
    {
      T temp = a->TElem<T>::GetData();
      delete a;
      start = 0;
      return temp;
    }
    else
    {
      while (b->GetNext() != 0)
      {
        a = b;
        b = b->GetNext();
      }
      T temp = b->GetData();
      delete b;
      a->SetNext(0);
      return temp;
    }
  }
}

template <class T>
bool TList<T>::IsFull()
{
  try
  {
    TElem<T>* a = new TElem<T>();
    if (a == NULL)
      return 1;
    else
    {
      delete a;
      return 0;
    }
  }
  catch (...)
  {
    return 0;
  }
  return true;
}

template <class T>
bool TList<T>::IsEmpty()
{
  if (start == 0)
    return 1;
  return 0;
}

template<class T>
inline void TList<T>::Print()
{
  if (start == 0)
    throw MyException("List is Empty.");
  else
  {
    TElem<T>* a = start;
    while (a->GetNext() != 0)
    {
      cout << a->GetData() << " ";
      a = a->GetNext();
    }
    cout << a->GetData() << " ";
  }

}
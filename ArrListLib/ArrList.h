#pragma once
#include "ExceptionLib.h"
#include "Queue.h"

template <class T>
class TArrList
{
private:
  T* elems;                  //Массив элементов списка
  int *nextInd;              //Массив индексов, указывающих на следующий элемент списка
  int *prevInd;              //Массив индексов, указывающих на предыдущий элемент списка
  int leng;                  //Размерность списка
  int count;                 //Количество элементов в списке
  int start;                 //Индекс начального элемента списка
  int end;                   //Индекс последнего элемента списка
  TQueue <int> freeElem;     //Очередь "пустых" ячеек в массиве  


public:
  TArrList(int _size = 10);     //Конструктор с параметром
  TArrList(TArrList<T> &arrl);  //Конструктор копирования
  ~TArrList();                  //Деструктор
  void Put(int n, T elem);      //Добавить промежуточный элемент
  T Get(int n);                 //Извлечь промежуточный элемент 
  void PutStart(T elem);        //Положить в начало списка
  void PutEnd(T elem);          //Положить в конец списка 
  T GetStart();                 //Извлечь из начала списка(с последующим удалением)
  T GetEnd();                   //Извлечь из конца списка(с последующим удалением)
  bool IsFull();                //Проверка на полноту
  bool IsEmpty();               //Проверка на пустоту
  void Print();                 //Вывод списка
};

template <class T>
TArrList<T>::TArrList(int _size) : freeElem(_size)
{
  if (_size <= 0)
    throw MyException("False leng");
  leng = _size;
  count = 0;
  start = -1;
  end = -1;
  elems = new T[leng];
  nextInd = new int[leng];
  prevInd = new int[leng];
  for (int i = 0; i < leng; i++)
  {
    nextInd[i] = -2;
    prevInd[i] = -2;
    freeElem.Put(i);
  }
}

template <class T>
TArrList<T>::TArrList(TArrList<T> &arrl)
{
  start = arrl.start;
  end = arrl.end;
  leng = arrl.leng;
  count = arrl.count;
  elems = new T[leng];
  nextInd = new int[leng];
  prevInd = new int[leng];
  freeElem = arrl.freeElem;
  for (int i = 0; i < leng; i++)
  {
    elems[i] = arrl.elems[i];
    nextInd[i] = arrl.nextInd[i];
    prevInd[i] = arrl.prevInd[i];
  }
}

template<class T>
inline TArrList<T>::~TArrList()
{
  delete[] elems;
  delete[] nextInd;
  delete[] prevInd;
}

template<class T>
void TArrList<T>::Put(int n, T elem)
{
  if (IsFull())
    throw MyException("List is Full");
  if (n < 1 || n > count - 1)
    throw MyException("Incorrect index");
  int ifree = freeElem.Get();
  elems[ifree] = elem;
  int one = start;
  int two = nextInd[start];
  for (int i = 0; i < n - 1; i++)
  {
    one = two;
    two = nextInd[two];
  }
  nextInd[ifree] = two;
  nextInd[one] = ifree;

  prevInd[ifree] = one;
  prevInd[two] = ifree;
  count++;
}

template<class T>
T TArrList<T>::Get(int n)
{
  if (IsEmpty())
    throw MyException("List is Empty");
  if (n < 1 || n > count - 1)
    throw MyException("Incorrect index");
  int ind = start;
  for (int i = 0; i < n; i++)
    ind = nextInd[ind];
  nextInd[prevInd[ind]] = nextInd[ind];
  prevInd[nextInd[ind]] = prevInd[ind];
  T temp = elems[ind];
  freeElem.Put(ind);
  count--;
  return temp;
}

template <class T>
void TArrList<T>::PutStart(T elem)
{
  if (IsFull())
    throw MyException("List is Full");
  int ifree = freeElem.Get();
  elems[ifree] = elem;
  nextInd[ifree] = start;
  if (start != -1)
    prevInd[start] = ifree;
  else
    end = ifree;
  start = ifree;
  count++;
}

template <class T>
void TArrList<T>::PutEnd(T elem)
{
  if (IsFull())
    throw MyException("List is Full");
  int ifree = freeElem.Get();
  elems[ifree] = elem;
  if (end != -1)
    nextInd[end] = ifree;
  else
  {
    start = ifree;
    prevInd[ifree] = -1;
  }
  prevInd[ifree] = end;
  end = ifree;
  count++;
}

template <class T>
T TArrList<T>::GetStart()
{
  if (IsEmpty())
    throw MyException("List is Empty");
  T elem = elems[start];
  freeElem.Put(start);
  int newstart = nextInd[start];
  nextInd[start] = prevInd[start] = -2;
  if (newstart != -1)
    prevInd[newstart] = -1;
  count--;
  start = newstart;
  return elem;
}

template <class T>
T TArrList<T>::GetEnd()
{
  if (IsEmpty())
    throw MyException("List is Empty");
  T elem = elems[end];
  int newFinish = prevInd[end];
  prevInd[end] = nextInd[end] = -2;
  freeElem.Put(end);
  end = newFinish;
  if (newFinish != -1)
    nextInd[newFinish] = -1;
  else
    start = -1;
  count--;
  return elem;
}

template <class T>
bool TArrList<T>::IsFull()
{
  if (count == leng)
    return true;
  return false;
}

template <class T>
bool TArrList<T>::IsEmpty()
{
  if (count == 0)
    return true;
  return false;
}

template<class T>
inline void TArrList<T>::Print()
{
  int it = start;
  for (int i = 0; i < count; i++)
  {
    cout << elems[it] << " ";
    it = nextInd[it];
  }
}
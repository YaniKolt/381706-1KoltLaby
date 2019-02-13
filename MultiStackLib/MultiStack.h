# pragma once
#include "NewStack.h"
#include "ExceptionLib.h"

template <class T>
class TMStack
{
protected:
  int leng;                                  //длина мультистека
  T* elem;                                   //массив элементов мультистека
  int countSt;                               //количество стеков в мультистеке
  TNewStack<T>** stackMas;                   //массив указателей на начало каждого стека в мультистеке
  
	int CountFree();                           //количество свободных элементов в мультистеке
  void Repack(int _st);                      //перепаковка стека с увеличением свободной памяти в стеке st

public:
  TMStack(int _countSt = 1, int _leng = 10);
  TMStack(TMStack &mst);

  int GetLeng();                             //получить длину мультистека
	T Get(int _st);                            //взять элемент из стека
  void Set(int _st, T _elem);                //положить в стек элемент
  bool IsFull(int _st);                      //проверить на полноту стек 
  bool IsEmpty(int _st);                     //проверить на пустоту стек 

  void PrintMStack();                        //вывод 
};


template <class T>
TMStack<T>::TMStack(int _countSt, int _leng)
{
  if (_countSt <= 0 || _leng <= 0)
    throw MyException("Error leng");
  countSt = _countSt;
  leng = _leng;

  stackMas = new TNewStack<T>*[countSt];
  elem = new T[leng];

  int* tmp1 = new int[countSt];
  for (int i = 0; i < countSt; i++)
    tmp1[i] = leng / countSt;
  tmp1[0] += leng % countSt;

  T** tmp2 = new T*[countSt];
  tmp2[0] = elem;
  for (int i = 1; i < countSt; i++)
    tmp2[i] = tmp2[i - 1] + tmp1[i - 1];

  for (int i = 0; i < countSt; i++)
    stackMas[i] = new TNewStack<T>(tmp1[i], tmp2[i]);
}

template <class T>
TMStack<T>::TMStack(TMStack &mst)
{
  leng = mst.leng;
  countSt = mst.countSt;
  if (leng == 0)
  {
    elem = NULL;
    stackMas = NULL;
  }
  else
  {
    elem = new T[leng];
    for (int i = 0; i < countSt; i++)
      elem[i] = mst.elem[i];

    stackMas = new TNewStack<T>*[countSt];

    int* tmp1 = new int[countSt];
    for (int i = 0; i < countSt; i++)
      tmp1[i] = mst.stackMas[i]->GetLength();

    T** tmp2 = new T*[countSt];
    tmp2[0] = elem;
    for (int i = 1; i < countSt; i++)
      tmp2[i] = tmp1[i - 1] + tmp2[i - 1];

    for (int i = 0; i < countSt; i++)
    {
      stackMas[i] = new TNewStack<T>(*mst.stackMas[i]);
      stackMas[i]->SetMas(tmp1[i], tmp2[i]);
    }
  }
}

template <class T>
int TMStack<T>::GetLeng()
{
  return leng;
}

template<class T>
T TMStack<T>::Get(int _st)
{
	if (_st < 0 || _st >= countSt)
		throw MyException("Error index");
	if (IsEmpty(_st))
		throw MyException("Stack is Empty");
	return stackMas[_st]->Get();
}

template<class T>
void TMStack<T>::Set(int _st, T _elem)
{
	if (_st < 0 || _st >= countSt)
		throw MyException("Error index");
	else if (this->CountFree() == 0)
		throw MyException("MultiStack is Full");
	else if (IsFull(_st))
		Repack(_st);
	stackMas[_st]->Push(_elem);
}

template<class T>
bool TMStack<T>::IsFull(int _st)
{
  if (_st < 0 || _st >= countSt)
    throw MyException("Error index");
  return (stackMas[_st]->GetFreeCell() == 0);
}

template<class T>
bool TMStack<T>::IsEmpty(int _st)
{
	if (_st < 0 || _st >= countSt)
		throw MyException("Error index");
	return (stackMas[_st]->GetFreeCell() == stackMas[_st]->GetLeng());
}

template <class T>
int TMStack<T>::CountFree()
{
	int count = 0;
	for (int i = 0; i < countSt; i++)
	{
		count += stackMas[i]->GetFreeCell();
	}
	return count;
}

template <class T>
void TMStack<T>::Repack(int _st)
{
	int free = CountFree();
	int add_ev = free / countSt;
	int add_full = free % countSt;
	int* new_size = new int[countSt];
	T** new_start = new T*[countSt];
	T** old_start = new T*[countSt];

	for (int i = 0; i < countSt; i++)
		new_size[i] = add_ev + stackMas[i]->GetTop();
	new_size[_st] += add_full;

	new_start[0] = old_start[0] = elem;
	for (int i = 1; i < countSt; i++)
	{
		new_start[i] = new_start[i - 1] + new_size[i - 1];
		old_start[i] = old_start[i - 1] + stackMas[i - 1]->GetLeng();
	}

	for (int i = 0; i < countSt; i++)
	{
		if (new_start[i] <= old_start[i])
			for (int j = 0; j < stackMas[i]->GetTop(); j++)
				new_start[i][j] = old_start[i][j];
		else
		{
			int s = i + 1;
			for (s; s < countSt; s++)
				if (new_start[s] <= old_start[s])
					break;
			for (int j = s - 1; j >= i; j--)
				for (int r = stackMas[j]->GetTop() - 1; r >= 0; r--)
					new_start[j][r] = old_start[j][r];
			i = s - 1;
		}
	}
	for (int i = 0; i < countSt; i++)
		stackMas[i]->SetMas(new_size[i], new_start[i]);
	delete[] new_size;
	delete[] new_start;
	delete[] old_start;
}

template<class T>
void TMStack<T>::PrintMStack()
{
  int m = 0;
  cout << "\n\nМультистек:";
  for (int i = 0; i < countSt; i++)
  {
    cout << endl << "Стек под номером: " << i + 1 << "\n";
    stackMas[i]->PrintNewStack();
  }
}
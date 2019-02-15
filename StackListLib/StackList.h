#pragma once
#include "List.h"
#include "ExceptionLib.h"

template <class T>
class TStackList : public TList<T>
{
protected:
	int leng;																	 //Максимальная длина стека

public:
	TStackList(int _leng = 10);
	TStackList(TStackList &stlst);
	~TStackList();

	T Get();																		//Изъять верхний элемент списка
	int GetMaxLeng();														//Получить размер стека
	int GetLeng();															//Получить текущее количество элементов в стеке

	void Put(T elem);														//Положить elem в начало списка

	bool IsEmpty();															//Проверка стека на списках на пустоту
	bool IsFull();															//Проверка стека на списках на полноту

	void PrintStLst();											  	//Вывод стека на списках на экран
};

template <class T>
TStackList<T>::TStackList(int _length) : TList<T>()
{
	if (_length <= 0)
		throw MyException("Error leng");

	leng = _length;
}

template <class T>
TStackList<T>::TStackList(TStackList<T> &stlst) : TList<T>(stlst)
{
	TList<T>::count = stlst.count;
}

template<class T>
TStackList<T>::~TStackList()
{
}

template <class T>
T TStackList<T>::Get()
{
	if (this->IsEmpty())
		throw MyException("Error stackList is Empty");

	return TList<T>::GetStart();
}

template <class T>
int TStackList<T>::GetMaxLeng()
{
	return leng;
}

template<class T>
inline int TStackList<T>::GetLeng()
{
	return TList<T>::count;
}

template <class T>
void TStackList<T>::Put(T elem)
{
	if (this->IsFull())
		throw MyException("Error stackList is Full");
	TList<T>::PutStart(elem);
}

template <class T>
bool TStackList<T>::IsEmpty()
{
	if (TList<T>::count == 0)
		return true;
	else
		return false;
}

template<class T>
bool TStackList<T>::IsFull()
{
	if (TList<T>::count == leng)
		return true;
	else
		return false;
}

template<class T>
void TStackList<T>::PrintStLst()
{
	if (this->IsEmpty())
		throw MyException("Error nothing to Print, StackList is Empty");
	TList<T>::Print();
}




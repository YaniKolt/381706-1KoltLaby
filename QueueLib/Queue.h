#pragma once
#include <iostream>
#include "Stack.h"
#include "ExceptionLib.h"

using namespace std;

template <class T>
class TQueue : public TStack <T> {//Очередь наследуется от стека
protected:
	int start;//Начало очереди
	int count;//Количество элементов
public:
	TQueue(int l = 0);
	TQueue(TQueue <T> &a);
	void Put(T a);//Положить в конец очереди
	T Get();//Взять первый элемент
	bool IsFull();//Проверка на полноту
	bool IsEmpty();//Проверка на пустоту
	void Print();

	T Top();
};


template <class T>
TQueue<T>::TQueue(int l) : TStack<T>(l) {
	if (l < 0)
		throw MyException("Error lengt");
	else
		if (l == 0)
		{
			start = 0;
			this->leng = 0;
			this->elem = 0;
			this->top = 0;
			count = 0;
		}
		else
		{
			this->leng = l;
			this->elem = new T[l];
			this->top = 0;
			start = 0;
			count = 0;
		}
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &a) : TStack<T>(a) {
	start = a.start; 
	count = a.count;
}

template <class T>
void TQueue<T>::Put(T el)
{
	if (IsFull())
		throw MyException("Queue is Full");
	else
	{
		TStack<T>::Put(el);
		TStack<T>::top = TStack<T>::top % TStack<T>::leng;
		count++;
	}
}

template<class T>
inline T TQueue<T>::Top()
{
	return TStack<T>::elem[start];
}

template <class T>
T TQueue<T>::Get()
{
	if (IsEmpty())
		throw MyException("Stack is Empty");
	else
	{
		T tmp = TStack<T>::elem[start];
		start = (start + 1) % TStack<T>::leng;
		count--;
		return tmp;
	}
}

template <class T>
bool TQueue<T>::IsFull() {
	return (count == TStack<T>::leng);
}

template <class T>
bool TQueue<T>::IsEmpty() {
	return (count == 0);
}

template<class T>
void TQueue<T>::Print()
{
	for (int i = start; i < TStack<T>::top; i = (i + 1) % TStack<T>::leng)
		cout << TStack<T>::elem[i];
}
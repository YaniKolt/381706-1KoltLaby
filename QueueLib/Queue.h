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
	TQueue(int L);
	TQueue(TQueue <T> &A);
	void Put(T A);//Положить в конец очереди
	T Get();//Взять первый элемент
	bool IsFull();//Проверка на полноту
	bool IsEmpty();//Проверка на пустоту
};


template <class T>
TQueue<T>::TQueue(int L) : TStack<T>(L) {
	if (L < 0)
		throw MyException("Error lengt");
	else
		if (L == 0)
		{
			start = 0;
			this->leng = 0;
			this->elem = 0;
			this->top = 0;
			count = 0;
		}
		else
		{
			this->leng = L;
			this->elem = new T[L];
			this->top = 0;
			start = 0;
			count = 0;
		}
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &A) : TStack<T>(A) {
	start = A.start; 
	count = A.count;
}

template <class T>
void TQueue<T>::Put(T A){
	if (IsFull())
		throw MyException("Queue is full");
	else {
		TStack<T>::elem[start] = A;
		start = (start + 1) % TStack<T>::leng;
		count++;
	}
}

template <class T>
T TQueue<T>::Get() {
	if (IsEmpty())
		throw MyException("Queue is empty");
	else {
		T temp = TStack<T>::elem[TStack<T>::top];
		TStack<T>::top = (TStack<T>::top + 1) % TStack<T>::leng;
		count--;
		
		return temp;
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
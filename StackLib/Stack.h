#pragma once
#include <iostream>
#include "ExceptionLib.h"

using namespace std;

template <class T>
class TStack{
protected:
	int leng;//Размер стека
	T* elem;//Элементы стека
	int top;//Верх
public:
	TStack(int L=0);
	TStack(TStack &A);
	~TStack();
	void Put(T A);//Положить
	T Get();//Взять
	bool IsFull();//Проверка на полноту
	bool IsEmpty();//Проверка на пустоту
};

//конструкторы
template <class T>
TStack<T>::TStack(int L){
	if (L < 0)
		throw MyException("error leng");
	else 
		if (L == 0){
		leng = 0;
		elem = 0;
		top = 0;
	}
	else{
		elem = new T[L];
		leng = L;
		top = 0;
	}
}

template <class T>
TStack<T>::TStack(TStack<T> &A){
	leng = A.leng;
	top = A.top;
	if (leng == 0)
		elem = 0;
	else{
		elem = new T[leng];
		for (int i = 0; i < leng; i++)
			elem[i] = A.elem[i];
	}
}
//деструктор
template <class T>
TStack<T> :: ~TStack(){
	if (elem != 0)
		delete[] elem;

	top = 0;
	leng = 0;
}

//положить
template <class T>
void TStack<T>::Put(T A){
	if (IsFull())
		throw MyException("Stack is full");
	else{
		elem[top] = A;
		top++;
	}
}

//взять
template <class T>
T TStack<T>::Get(){
	if (IsEmpty())
		throw MyException("Stack is empty");
	else{
		top--;
		return elem[top];
	}
}

//проверка на полноту
template <class T>
bool TStack<T>::IsEmpty(){
	return (top == 0);
}


//проверка на пустоту
template <class T>
bool TStack<T>::IsFull(){
	return (top >= leng);
}
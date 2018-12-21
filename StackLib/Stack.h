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
	TStack(TStack &a);
	~TStack();
	int GetLength();// Получить длину стека
	void PrintStack(); //Вывод стека на экран
	TStack& operator=(const TStack<T>& st); //Присваивание стека
	int operator==(const TStack<T>& st) const; //Проверка на равенство
	int operator!=(const TStack<T>& st) const; // Проверка на неравенство

	void Put(T a);//Положить
	T Get();//Взять
	bool IsFull();//Проверка на полноту
	bool IsEmpty();//Проверка на пустоту
};

//конструкторы
template <class T>
TStack<T>::TStack(int l){
	if (l < 0)
		throw MyException("Error leng");
	else 
		if (l == 0){
		leng = 0;
		elem = 0;
		top = 0;
	}
	else{
		elem = new T[l];
		leng = l;
		top = 0;
	}
}

template <class T>
TStack<T>::TStack(TStack<T> &a){
	leng = a.leng;
	top = a.top;
	if (leng == 0)
		elem = 0;
	else{
		elem = new T[leng];
		for (int i = 0; i < leng; i++)
			elem[i] = a.elem[i];
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
void TStack<T>::Put(T a){
	if (IsFull())
		throw MyException("Stack is full");
	else{
		elem[top] = a;
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


template <class T>
int TStack<T>::GetLength()
{
	return leng;
}

template <class T>
void TStack<T>::PrintStack()
{
	for (int i = top - 1; i >= 0; i--)
		cout << " " << elem[i];
}


template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& a)
{
	if (this != &a)
	{
		delete[] elem;
		top = a.top;
		leng = a.leng;
		elem = new T[leng];
		for (int i = 0; i < leng; i++)
			elem[i] = a.elem[i];
	}
	return *this;
}


template <class T>
int TStack<T>::operator==(const TStack<T>& a) const
{
	if (top != a.top)
		return 0;
	if (leng != a.leng)
		return 0;
	for (int i = 0; i < top; i++)
		if (elem[i] != a.elem[i])
			return 0;
	return 1;
}


template <class T>
int TStack<T>::operator!=(const TStack<T>& a) const
{
	return !(*this == a);
}

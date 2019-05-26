#pragma once
#include <iostream>
#include "ExceptionLib.h"

template <class T> 
class TElem
{
protected:
	string key;                           //Ключ
	T data;                               //Данные 
public:
	TElem(string _key = "", T _data = 0); //конструктор-инициализатор
	TElem(TElem &elem);                   //конструктор копирования
	void SetKey(string _key);             //Задать ключ
	void SetData(T _data);                //Задать данные
	string GetKey();                      //Получить ключ
	T GetData();                          // Получить данные
	T& GetDataAddress();                  //получить адрес данных
	TElem<T>& operator=(TElem &elem);     //Оператор присваивания
	bool operator==(TElem &elem);         //Сравнение на равенство

};

template <class T>
TElem<T>::TElem(string _key, T _data)
{
	key = _key;
	data = _data;
}

template <class T>
TElem<T>::TElem(TElem &elem)
{
	key = elem.key;
	data = elem.data;
}

template <class T>
TElem<T>& TElem<T>::operator=(TElem &elem)
{
	if (this != &elem)
	{
		key = elem.key;
		data = elem.data;
	}
	return *this;
}

template <class T>
bool TElem<T>::operator==(TElem &elem)
{
	if (key != elem.key)
		return 0;
	if (data != elem.data)
		return 0;
	return 1;
}

template <class T>
void TElem<T>::SetKey(string _key)
{
	key = _key;
}

template <class T>
string TElem<T>::GetKey()
{
	return key;
}

template <class T>
void TElem<T>::SetData(T _data)
{
	data = _data;
}

template <class T>
T TElem<T>::GetData()
{
	return data;
}

template <class T>
T& TElem<T>::GetDataAddress()
{
	return data;
}
﻿#pragma once
#include "ExceptionLib.h"

template <class T>
class TVector
{
protected:
  T *vector;     //указатель на вектор 
  int leng;       //длина вектора

public:

	//конструкторы
  TVector(int l = 0);
  TVector(const TVector &a);                
  virtual ~TVector();

  int GetLeng() const; //получить длину вектора
  virtual T& operator[](int m);           //доступ к определенному элементу в позиции m

  //булевые операторы
  bool operator==(const TVector &a) const;  // булевый оператор равно
  bool operator!=(const TVector &a) const;  // булевый оператор не равно
 
	virtual TVector& operator=(const TVector &a); // присвоить

	//арифметические операции с числом(скаляром)
  TVector operator+(const T &n);   //сложение с числом
  TVector operator-(const T &n);   //вычитание числа
  TVector operator*(const T &n);   //умножение на число

	//арифметические операции
  TVector operator+(const TVector &a);     //сложение
  TVector operator-(const TVector &a);     //вычитание
  T operator*(const TVector &A);     //скалярное произведение
	
  //ввод-вывод
  template <class ValType1>
  friend istream& operator>>(istream &in, TVector<ValType1>& a);
  template <class ValType1>
  friend ostream& operator<<(ostream &out, const TVector<ValType1>& a);
}; 

template <class T>
TVector<T>::TVector(int l)
{
	if (l < 0)
		throw MyException("Error leng");
  else
    if (l == 0) 
    {
      leng = l;
      vector = NULL;
    }
    else 
    {
      leng = l;
      vector = new T[leng];
      for (int i = 0; i < leng; i++)
        vector[i] = 0;
    }
} 

template <class T> 
TVector<T>::TVector(const TVector<T> &a) 
{
  leng = a.leng;
  if (leng == 0)
    vector = NULL;
  else 
  {
    vector = new T[leng];
    for (int i = 0; i < leng; i++)
      vector[i] = a.vector[i];
  }
} 
template<class T>
TVector<T>::~TVector() 
{
  if (leng > 0)
  {
    leng = 0;
    delete[] vector;
    vector = NULL;
  }
} 

template <class T>
int TVector<T>::GetLeng() const
{ 
  return leng; 
}

template <class T> 
T& TVector<T>::operator[](int m)
{
	if (m >= 0 && m < leng)
		return vector[m];
	else
		throw MyException("Error position");
} 

template <class T>
bool TVector<T>::operator==(const TVector &a) const
{
	if (leng != a.leng)
		return 0;
	else
		for (int i = 0; i < leng; i++)
			if (vector[i] != a.vector[i])
			{
        return 0;
			}
	return 1;
} 

template <class T> 
bool TVector<T>::operator!=(const TVector &a) const
{
  return !(*this == a);
}

template <class T> 
TVector<T>& TVector<T>::operator=(const TVector &a)
{
	if (this != &a)
	{
		delete[] vector;
		leng = a.leng;
		vector = new T[leng];
		for (int i = 0; i < leng; i++)
			vector[i] = a.vector[i];
	}
	return *this;
} 

template <class T>
TVector<T> TVector<T>::operator+(const T &n)
{
	TVector<T> res(*this);
	for (int i = 0; i < leng; i++)
		res.vector[i] += n;
	return res;
}

template <class T>
TVector<T> TVector<T>::operator-(const T &n)
{
	TVector<T> res(*this);
	for (int i = 0; i < leng; i++)
		res.vector[i] -= n;
	return res;
}

template <class T>
TVector<T> TVector<T>::operator*(const T &n)
{
	TVector<T> res(*this);
	for (int i = 0; i < leng; i++)
		res.vector[i] = res.vector[i] * n;
	return res;
} 

template <class T>
TVector<T> TVector<T>::operator+(const TVector<T> &a)
{
  if (leng != a.leng)
    throw MyException("Error leng operand");
  TVector<T> rez(*this);
  for (int i = 0; i < leng; i++)
    rez[i] = (*this)[i] + a.vector[i];
  return rez;
} 

template <class T>
TVector<T> TVector<T>::operator-(const TVector<T> &a)
{
  if (leng != a.leng)
    throw MyException("Error leng operand");
  TVector<T> rez(*this);
  for (int i = 0; i < leng; i++)
    rez[i] = (*this)[i] - a.vector[i];
  return rez;
}

template <class T> 
T TVector<T>::operator*(const TVector<T> &a)
{
  if (leng != a.leng)
    throw MyException("Error leng operand");
  int temp = 0;
  for (int i = 0; i < leng; i++)
    temp += vector[i] * a.vector[i];
  return temp;
} 

template <class T>
istream& operator>>(istream &in, TVector<T> &a)
{
	for (int i = 0; i < a.leng; i++)
		in >> a.vector[i];
	return in;
}

template <class T>
ostream& operator<<(ostream &out, const TVector<T> &a)
{
	for (int i = 0; i < a.leng; i++)
		out << a.vector[i] << '\t';
	return out;
}


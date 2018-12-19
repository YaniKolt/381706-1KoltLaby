#pragma once
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
  TVector(const TVector &A);                
  virtual ~TVector();

  int GetLeng() const; //получить длину вектора
  virtual T& operator[](int m);           //доступ к определенному элементу в позиции m

  //булевые операторы
  bool operator==(const TVector &A) const;  // булевый оператор равно
  bool operator!=(const TVector &A) const;  // булевый оператор не равно
 
	virtual TVector& operator=(const TVector &A); // присвоить

	//арифметические операции с числом(скаляром)
  TVector operator+(const T &n);   //сложение с числом
  TVector operator-(const T &n);   //вычитание числа
  TVector operator*(const T &n);   //умножение на число

	//арифметические операции
  TVector operator+(const TVector &A);     //сложение
  TVector operator-(const TVector &A);     //вычитание
  T operator*(const TVector &A);     //скалярное произведение
	
  //ввод-вывод
  template <class ValType1>
  friend istream& operator>>(istream &in, TVector<ValType1>& A);
  template <class ValType1>
  friend ostream& operator<<(ostream &out, const TVector<ValType1>& A);
}; 

template <class T>
TVector<T>::TVector(int l)
{
	if (l < 0)
		throw MyException("error leng");
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
TVector<T>::TVector(const TVector<T> &A) 
{
  leng = A.leng;
  if (leng == 0)
    vector = NULL;
  else 
  {
    vector = new T[leng];
    for (int i = 0; i < leng; i++)
      vector[i] = A.vector[i];
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
		throw MyException("error position");
} 

template <class T>
bool TVector<T>::operator==(const TVector &A) const
{
	if (leng != A.leng)
		return 0;
	else
		for (int i = 0; i < leng; i++)
			if (vector[i] != A.vector[i])
			{
        return 0;
			}
	return 1;
} 

template <class T> 
bool TVector<T>::operator!=(const TVector &A) const
{
  return !(*this == A);
}

template <class T> 
TVector<T>& TVector<T>::operator=(const TVector &A)
{
	if (this != &A)
	{
		delete[] vector;
		leng = A.leng;
		vector = new T[leng];
		for (int i = 0; i < leng; i++)
			vector[i] = A.vector[i];
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
TVector<T> TVector<T>::operator+(const TVector<T> &A)
{
  if (leng != A.leng)
    throw MyException("error leng operand");
  TVector<T> rez(*this);
  for (int i = 0; i < leng; i++)
    rez[i] = (*this)[i] + A.vector[i];
  return rez;
} 

template <class T>
TVector<T> TVector<T>::operator-(const TVector<T> &A)
{
  if (leng != A.leng)
    throw MyException("error leng operand");
  TVector<T> rez(*this);
  for (int i = 0; i < leng; i++)
    rez[i] = (*this)[i] - A.vector[i];
  return rez;
}

template <class T> 
T TVector<T>::operator*(const TVector<T> &A)
{
  if (leng != A.leng)
    throw MyException("error leng operand");
  int temp = 0;
  for (int i = 0; i < leng; i++)
    temp += vector[i] * A.vector[i];
  return temp;
} 

template <class T>
istream& operator>>(istream &in, TVector<T> &A)
{
	for (int i = 0; i < A.leng; i++)
		in >> A.vector[i];
	return in;
}

template <class T>
ostream& operator<<(ostream &out, const TVector<T> &A)
{
	for (int i = 0; i < A.leng; i++)
		out << A.vector[i] << '\t';
	return out;
}


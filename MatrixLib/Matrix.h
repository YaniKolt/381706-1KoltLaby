#pragma once
#include "Vector.h"

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
	//конструкторы
	TMatrix(int l = 10);
	TMatrix(const TMatrix &Mt);
	TMatrix(const TVector<TVector<T> > &Mt);
	virtual ~TMatrix();
	//булевые
	bool operator==(const TMatrix &Mt) const;      // булевый оператор равно
	bool operator!=(const TMatrix &Mt) const;      // булевый оператор не равно

	TMatrix& operator=(const TMatrix &Mt);        // присваивание
	//арифметические операции
	TMatrix operator+(const TMatrix &Mt);         // сложение
	TMatrix operator-(const TMatrix &Mt);         // вычитание
	TMatrix<T> operator*(const TMatrix<T> &Mt);    // умножение
	//ввод-вывод
	template <class ValType2>
	friend istream& operator>>(istream &in, TMatrix<ValType2> &Mt);
	template <class ValType2>
	friend ostream & operator<<(ostream &out, const TMatrix<ValType2> &Mt);
};

template <class T>
TMatrix<T>::TMatrix(int l) :TVector<TVector<T> >(l)
{
	if (l <= 0 || l > 1000)
		throw MyException("error leng");
	for (int i = 0; i < l; i++)
		this->vector[i] = TVector<T>(l - i);
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &Mt) :TVector<TVector<T> >(Mt)
{}

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &Mt) : TVector<TVector<T> >(Mt)
{}

template <class T>
TMatrix<T>::~TMatrix()
{}

template <class T >
bool TMatrix<T>::operator==(const TMatrix<T> &Mt) const
{
	return TVector<TVector<T> >::operator==(Mt);
}

template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &Mt) const
{
	return TVector<TVector<T> >::operator!=(Mt);
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &Mt)
{
	TVector<TVector<T> >::operator=(Mt);
	return *this;
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &Mt)
{
	if (this->leng == Mt.leng)
		return TVector<TVector<T> >::operator+(Mt);
	else
		throw MyException("error leng operand");
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &Mt)
{
	if (this->leng == Mt.leng)
		return TVector<TVector<T> >::operator-(Mt);
	else
		throw MyException("error leng operand");
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &Mt)
{
	if (this->leng != Mt.leng)
		throw MyException("error leng operand");
	TMatrix <T> rez(this->leng);
	for (int i = 0; i < this->leng; i++)
		for (int j = i; j < this->leng; j++) {
			for (int k = i; k <= j; k++)
				rez.vector[i][j - i] += this->vector[i][k - i] * Mt.vector[k][j - k];
		}
	return rez;
}

template <class ValType2>
istream& operator>>(istream &in, TMatrix<ValType2> &Mt)
{
	for (int i = 0; i < Mt.leng; i++)
		in >> Mt.vector[i];
	return in;
}

template <class ValType2>
ostream & operator<<(ostream &out, const TMatrix<ValType2> &Mt)
{
	for (int i = 0; i < Mt.leng; i++)
		out << Mt.vector[i] << endl;
	return out;
}

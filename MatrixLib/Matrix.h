#pragma once
#include <iomanip>
#include "Vector.h"

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
	//конструкторы
	TMatrix(int l = 10);
	TMatrix(const TMatrix & mtr);
	TMatrix(const TVector<TVector<T> > & mtr);
	virtual ~TMatrix();
	//булевые
	bool operator==(const TMatrix & mtr) const;      // булевый оператор равно
	bool operator!=(const TMatrix & mtr) const;      // булевый оператор не равно

	TMatrix& operator=(const TMatrix & mtr);        // присваивание
	//арифметические операции
	TMatrix operator+(const TMatrix & mtr);         // сложение
	TMatrix operator-(const TMatrix & mtr);         // вычитание
	TMatrix<T> operator*(const TMatrix<T> & mtr);    // умножение
	//ввод-вывод
	template <class ValType2>
	friend istream& operator>>(istream &in, TMatrix<ValType2> & mtr);
	template <class ValType2>
	friend ostream & operator<<(ostream &out, const TMatrix<ValType2> & mtr);
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
TMatrix<T>::TMatrix(const TMatrix<T> & mtr) :TVector<TVector<T> >(mtr)
{}

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > & mtr) : TVector<TVector<T> >(mtr)
{}

template <class T>
TMatrix<T>::~TMatrix()
{}

template <class T >
bool TMatrix<T>::operator==(const TMatrix<T> & mtr) const
{
	return TVector<TVector<T> >::operator==(mtr);
}

template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> & mtr) const
{
	return TVector<TVector<T> >::operator!=(mtr);
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> & mtr)
{
	TVector<TVector<T> >::operator=(mtr);
	return *this;
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> & mtr)
{
	if (this->leng == mtr.leng)
		return TVector<TVector<T> >::operator+(mtr);
	else
		throw MyException("error leng operand");
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> & mtr)
{
	if (this->leng == mtr.leng)
		return TVector<TVector<T> >::operator-(mtr);
	else
		throw MyException("error leng operand");
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> & mtr)
{
	if (this->leng != mtr.leng)
		throw MyException("error leng operand");
	TMatrix <T> rez(this->leng);
	for (int i = 0; i < this->leng; i++)
		for (int j = i; j < this->leng; j++) {
			for (int k = i; k <= j; k++)
				rez.vector[i][j - i] += this->vector[i][k - i] * mtr.vector[k][j - k];
		}
	return rez;
}

template <class ValType2>
istream& operator>>(istream &in, TMatrix<ValType2> & mtr)
{
	for (int i = 0; i < mtr.leng; i++)
		in >> mtr.vector[i];
	return in;
}

template <class ValType2>
ostream & operator<<(ostream &out, const TMatrix<ValType2> & mtr)
{
	for (int i = 0; i < mtr.leng; i++)
	{
		for (int k = 0; k < i; k++)
			out << "  \t";

			out << setprecision(5) << mtr.vector[i] << endl;
	}
	return out;
}


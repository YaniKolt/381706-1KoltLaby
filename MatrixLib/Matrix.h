#pragma once
#include "Vector.h"
#include <iomanip> 

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
	//êîíñòðóêòîðû
	TMatrix(int l = 10);
	TMatrix(const TMatrix &Mt);
	TMatrix(const TVector<TVector<T> > &Mt);
	virtual ~TMatrix();
	//áóëåâûå
	bool operator==(const TMatrix &Mt) const;      // áóëåâûé îïåðàòîð ðàâíî
	bool operator!=(const TMatrix &Mt) const;      // áóëåâûé îïåðàòîð íå ðàâíî

	TMatrix& operator=(const TMatrix &Mt);        // ïðèñâàèâàíèå
	//àðèôìåòè÷åñêèå îïåðàöèè
	TMatrix operator+(const TMatrix &Mt);         // ñëîæåíèå
	TMatrix operator-(const TMatrix &Mt);         // âû÷èòàíèå
	TMatrix<T> operator*(const TMatrix<T> &Mt);    // óìíîæåíèå
	TMatrix<T> operator/(const TMatrix<T> &MT); //äåëåíèå
	//ââîä-âûâîä
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

template <class T>
TMatrix<T> TMatrix<T>::operator/(const TMatrix<T> &Matr)
{
	if (this->leng != Matr.leng)
		throw MyException("Error length operand");
	TMatrix <T> copy(*this);
	TMatrix <T> rez(this->leng);
	TMatrix <T> copyMt(Matr);

	for (int i = 0; i < this->leng; i++)
		rez[i][0] = 1 / copyMt[i][0];

	for (int i = 0; i < this->leng - 1; i++)
		for (int j = 1; j < this->leng - i; j++)
		{
			if (copyMt[i][j] != 0)
			{
				T temp = copyMt[i][j];
				rez[i][j] = (-1) * copyMt[i][j] * rez[i + j][0];
				for (int k = j, l = 0; k < this->leng - i; k++)
					copyMt[i][k] = copyMt[i][k] - copyMt[j][l++] * temp;
			}
		}
	rez = copy * rez;
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
	{
		for (int k = 0; k < i; k++)
			out << "  \t";
		out << setprecision(5) << Mt.vector[i] << endl;
	}
	return out;
}

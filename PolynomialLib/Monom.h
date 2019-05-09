#pragma once
#include "ExceptionLib.h"

class TMonom
{
protected:
  TMonom* next;																	//указатель на следующий моном
  int* deg;																		  //массив степеней
  double coef;																	//коэффицент перед мономом
  int countMon;																	//количество переменных в мономе

public:
  TMonom();
  TMonom(int _count, int* _deg, double _coef);
  TMonom(const TMonom& mon);
  virtual ~TMonom();

	void SetNext(TMonom* _next);                //ввести адрес следующего монома
	void SetDeg(int* _deg);											//ввести массив степеней монома
	void SeCoef(double _coef);									//ввести коэффициент при мономе
	void SetCountMon(int _count);								//ввести количество переменных в мономе

  TMonom* GetNext();													//получить адрес следующего монома
  int* GetDeg();															//получить массив степеней монома
  double GetCoef();														//получить коэффициент при мономе
  int GetCountMon();													//получить количество переменных в мономе

  TMonom operator+(TMonom& mon);
  TMonom operator+=(TMonom& mon);

	TMonom operator-(TMonom& mon);
	TMonom operator-=(TMonom& mon);

  TMonom operator*(const TMonom& mon) const;
  TMonom operator*=(TMonom& mon);

	TMonom& operator=(const TMonom& mon);
  bool operator==(TMonom& mon);
  bool operator>(TMonom& mon);
  bool operator<(TMonom& mon);

  friend istream& operator>>(istream& istr, TMonom& mon);
  friend ostream& operator<<(ostream& ostr, TMonom& mon);
};

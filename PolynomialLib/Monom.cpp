#include "Monom.h"


TMonom::TMonom()
{
  next = NULL;
  deg = NULL;
  coef = 0;
  countMon = 0;
}

//------------------------------------------------------------------------------
TMonom::TMonom(int _count, int* _deg, double _koef)
{
  if (_count < 0)
    throw MyException("Error monom`s count");

  else if (_count == 0)
  {
    deg = NULL;
    countMon = _count;
    coef = _koef;
    next = NULL;
  }
  else
  {
    countMon = _count;
    coef = _koef;
    next = NULL;
    deg = new int[_count];
    for (int i = 0; i < _count; i++)
    {
      if (_deg[i] >= 0)
        deg[i] = _deg[i];
      else
        throw MyException("Error degree");
    }
  }
}

TMonom::TMonom(const TMonom &mon)
{
  countMon = mon.countMon;
  coef = mon.coef;
  next = mon.next;
  deg = new int[countMon];
  for (int i = 0; i < countMon; i++)
  {
    deg[i] = mon.deg[i];
  }
}
 
TMonom::~TMonom()
{
  if (deg != 0)
    delete[]deg;
  countMon = 0;
  coef = 0;
  next = 0;
}

TMonom* TMonom::GetNext()
{
  return next;
}

int* TMonom::GetDeg()
{
  return deg;
}

double TMonom::GetCoef()
{
  return coef;
}

int TMonom::GetCountMon()
{
  return countMon;
}

void TMonom::SetNext(TMonom* _next)
{
  next = _next;
}

void TMonom::SetDeg(int* _deg)
{
  for (int i = 0; i < countMon; i++)
  {
    if (_deg[i] >= 0)
      deg[i] = _deg[i];
    else
      throw MyException("Error degree");
  }
}

void TMonom::SeCoef(double _coef)
{
  coef = _coef;
}

void TMonom::SetCountMon(int _count)
{
  if (_count < 0)
    throw MyException("Error monom`s count");

  else if (_count == 0)
  {
    if (deg != 0)
      delete[] deg;
    deg = 0;
    countMon = 0;
  }
  else
  {
    int *tmp = new int[countMon];
    for (int i = 0; i < countMon; i++)
      tmp[i] = deg[i];
    delete[]deg;
    deg = new int[_count];
    int i = 0;
    if (countMon < _count)
    {
      for (; i < countMon; i++)
        deg[i] = tmp[i];
      for (; i < _count; i++)
        deg[i] = 0;
    }
    if (_count < countMon)
      for (; i < _count; i++)
        deg[i] = tmp[i];
    countMon = _count;
  }
}

TMonom TMonom::operator+(TMonom& mon)
{
  TMonom tmp(mon);
  if (countMon != mon.countMon)
    throw MyException("Error different monoms`s count");

	for (int i = 0; i < mon.countMon; i++)
		if (deg[i] != mon.deg[i])
    throw MyException("Error different degree");

  tmp.coef = coef + mon.coef;
  return tmp;
}

TMonom TMonom::operator+=(TMonom & mon)
{
  if (countMon != mon.countMon)
    throw MyException("Error different monoms`s count");

	for (int i = 0; i < mon.countMon; i++)
		if (deg[i] != mon.deg[i])
    throw MyException("Error different degree");

  coef += mon.coef;
  return *this;
}

TMonom TMonom::operator-(TMonom& mon)
{
  TMonom tmp(mon);
  if (countMon != mon.countMon)
    throw MyException("Error different monoms`s count");

	for (int i =0; i<mon.countMon; i++)
  if (deg[i]!=mon.deg[i])
    throw MyException("Error different degree");

  tmp.coef = coef - mon.coef;
  return tmp;
}

TMonom TMonom::operator-=(TMonom & mon)
{
  if (countMon != mon.countMon)
		throw MyException("Error different monoms`s count");

	for (int i = 0; i < mon.countMon; i++)
		if (deg[i] != mon.deg[i])
			throw MyException("Error different degree");

  coef -= mon.coef;
  return *this;
}

TMonom TMonom::operator*(const TMonom& mon) const
{
  if (countMon != mon.countMon)
    throw MyException("Error different monoms`s count");

  TMonom tmp(mon);
  tmp.coef = coef * mon.coef;
  for (int i = 0; i < countMon; i++)
    tmp.deg[i] = deg[i] + mon.deg[i];
  return tmp;
}

TMonom TMonom::operator*=(TMonom& mon)
{
  if (countMon != mon.countMon)
		throw MyException("Error different monoms`s count");

  coef = coef * mon.coef;
  for (int i = 0; i < countMon; i++)
    deg[i] += mon.deg[i];
  return *this;
}

TMonom& TMonom::operator=(const TMonom& mon)
{
	if (countMon != mon.countMon)
		throw MyException("Error leng not equal");

	coef = mon.coef;
	countMon = mon.countMon;
	next = mon.next;
	delete[] deg;
	deg = new int[countMon];
	for (int i = 0; i < countMon; i++)
		deg[i] = mon.deg[i];
	return *this;
}

bool TMonom::operator==(TMonom& mon)
{
  if (countMon != mon.countMon)
		throw MyException("Error different monoms`s count");
	for (int i = 0; i < countMon; i++)
		if (deg[i] != mon.deg[i])
			return false;
  return true;
}

bool TMonom::operator>(TMonom& mon)
{
  if (countMon != mon.countMon)
		throw MyException("Error different monoms`s count");

  if (*this == mon)
    throw MyException("Error monoms are equal");

  for (int i = 0; i < countMon; i++)
  {
    if (deg[i] == mon.deg[i])
      continue;
    else if (deg[i] > mon.deg[i])
      return true;
    else
      return false;
  }
	if (coef < mon.coef)
		return false;
  return true;
}

bool TMonom::operator<(TMonom& mon)
{
  if (countMon != mon.countMon)
		throw MyException("Error different monoms`s count");

  if (*this == mon)
    throw MyException("Error monoms are equal");

  for (int i = 0; i < countMon; i++)
  {
    if (deg[i] == mon.deg[i])
      continue;
    else if (deg[i] < mon.deg[i])
      return true;
    else
      return false;
  }
  if (coef > mon.coef)
    return false;
  return true;
}

istream& operator>>(istream& istr, TMonom& mon)
{
  istr >> mon.coef;
  for (int i = 0; i < mon.countMon; i++)
    istr >> mon.deg[i];
  return istr;
}

ostream& operator<<(ostream& ostr, TMonom& mon)
{
  ostr << mon.coef;
  if (mon.coef != 0)
  {
    for (int i = 0; i < mon.countMon; i++)
      if (mon.deg[i] != 0)
      {
        ostr << "*x" << i;
        if (mon.deg[i] != 1)
          ostr << "^" << mon.deg[i];
      }
  }
  return ostr;
}

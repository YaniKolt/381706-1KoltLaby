#include "Polynomial.h"

TPolynom::TPolynom(int _count)
{
  if (_count <= 0)
    throw MyException("Error polinomial`s count");
  countVar = _count;
  leng = 0;
  start = 0;
}

TPolynom::TPolynom(TPolynom &pol)
{
  countVar = pol.countVar;
  leng = pol.leng;
  if (pol.start == 0)
    start = 0;
  else
  {
    start = new TMonom(*pol.start);
    TMonom* tmon1 = pol.start;
    TMonom* tmon2 = start;
    while (tmon1->GetNext() != 0)
    {
      tmon2->SetNext(new TMonom(*(tmon1->GetNext())));
      tmon2 = tmon2->GetNext();
      tmon1 = tmon1->GetNext();
    }
    tmon2->SetNext(NULL);
  }
}

TPolynom::~TPolynom()
{
}

int TPolynom::GetLeng()
{
  return leng;
}

TMonom* TPolynom::GetStart()
{
  return start;
}


TPolynom TPolynom::operator+(TPolynom &pol)
{
  if (this->countVar != pol.countVar)
    throw MyException("Error different polinomials`s count");

  TPolynom res(countVar);
  TMonom *tmon1 = start, *tmon2 = pol.start, *tmon = res.start;
  while ((tmon1 != 0) && (tmon2 != 0))
  {
    TMonom *t;
    if ((*tmon1) == (*tmon2))
    {
      TMonom k = (*tmon1);
      k += (*tmon2);
      t = new TMonom(k);
      if (t->GetCoef() == 0)
        continue;
      tmon1 = tmon1->GetNext();
      tmon2 = tmon2->GetNext();
    }
    else if ((*tmon1) < (*tmon2))
    {
      t = new TMonom((*tmon2));
      if (t->GetCoef() == 0)
        continue;
      tmon2 = tmon2->GetNext();
    }
    else if ((*tmon1) > (*tmon2))
    {
      t = new TMonom((*tmon1));
      if (t->GetCoef() == 0)
        continue;
      tmon1 = tmon1->GetNext();
    }
    if (tmon == 0)
    {
      tmon = t;
      res.start = t;
      res.leng++;
    }
    else
    {
      tmon->SetNext(t);
      res.leng++;
      tmon = tmon->GetNext();
    }
  }
  if (tmon1 == 0)
    tmon1 = tmon2;
  while (tmon1 != 0)
  {
    if (tmon1->GetCoef() == 0)
      continue;
    tmon->SetNext(new TMonom(*tmon1));
    tmon1 = tmon1->GetNext();
    res.leng++;
    tmon = tmon->GetNext();
  }
  return res;
}

TPolynom &TPolynom::operator+=(TMonom &mon)
{
	if (this->countVar != mon.GetCountMon())
		throw MyException("Error different polinomial`s count");

	if (mon.GetCoef() == 0)
		return *this;
	if (start == 0)
		start = new TMonom(mon);
	else
	{
		TMonom *_start, *_end;
		_start = start;
		_end = start->GetNext();
		if (*start < mon)
		{
			TMonom* tmp = new TMonom(mon);
			tmp->SetNext(start);
			start = tmp;
		}
		else if (*start == mon)
		{
			*start += mon;
			if (start->GetCoef() == 0)
			{
				TMonom* temp = start->GetNext();
				delete[] start;
				start = temp;
			}
		}
		else
		{
			while (_end != 0)
			{
				if (*_end == mon)
				{
					*_end += mon;
					if (_end->GetCoef() == 0)
					{
						start->SetNext(_end->GetNext());
						delete[] _end;
					}
					// size++;
					return *this;
				}
				if (*_end < mon)
				{
					TMonom* tmp = new TMonom(mon);
					_start->SetNext(tmp);
					tmp->SetNext(_end);
					leng++;
					return *this;
				}
				_start = _end;
				_end = _end->GetNext();
			}
			_start->SetNext(new TMonom(mon));
		}
	}
	leng++;
	return *this;
}

TPolynom TPolynom::operator-(TPolynom &pol)
{
  if (this->countVar != pol.countVar)
    throw MyException("Error different polinomial`s count");

  TPolynom res(countVar);
  TMonom *tmon1 = start, *tmon2 = pol.start, *tmon = res.start;
  while ((tmon1 != 0) && (tmon2 != 0))
  {
    TMonom *t;
    if ((*tmon1) == (*tmon2))
    {
      TMonom k = (*tmon1);
      k -= (*tmon2);
      t = new TMonom(k);
      tmon1 = tmon1->GetNext();
      tmon2 = tmon2->GetNext();
    }
    else if ((*tmon1) < (*tmon2))
    {
      t = new TMonom((*tmon2));
      if (t->GetCoef() == 0)
        continue;
      t->SeCoef(t->GetCoef() * (-1));
      tmon2 = tmon2->GetNext();
    }
    else if ((*tmon1) > (*tmon2))
    {
      t = new TMonom((*tmon1));
      if (t->GetCoef() == 0)
        continue;
      tmon1 = tmon1->GetNext();
    }
    if (t->GetCoef() == 0)
      continue;
    if (tmon == 0)
    {
      tmon = t;
      res.start = t;
      res.leng++;
    }
    else
    {
      tmon->SetNext(t);
      res.leng++;
      tmon = tmon->GetNext();
    }
  }
  while (tmon1 != 0)
  {
    if (tmon1->GetCoef() == 0)
      continue;
    tmon->SetNext(new TMonom(*tmon1));
    tmon1 = tmon1->GetNext();
    res.leng++;
    tmon = tmon->GetNext();
  }
  while (tmon2 != 0)
  {
    if (tmon2->GetCoef() == 0)
      continue;
    TMonom t(*tmon2);
    t.SeCoef(t.GetCoef() * (-1));
    tmon->SetNext(&t);
    tmon2 = tmon2->GetNext();
    res.leng++;
    tmon = tmon->GetNext();
  }
  return res;
}


TPolynom &TPolynom::operator-=(TMonom &mon)
{
	if (this->countVar != mon.GetCountMon())
		throw MyException("Error different polinomial`s count");

	if (mon.GetCoef() == 0)
		return *this;
	mon.SeCoef(mon.GetCoef() * (-1));
	if (start == 0)
		start = new TMonom(mon);
	else
	{
		TMonom *_start, *_end;
		_start = start;
		_end = start->GetNext();
		if (*start < mon)
		{
			TMonom* tmp = new TMonom(mon);
			tmp->SetNext(start);
			start = tmp;
		}
		else if (*start == mon)
		{
			*start -= mon;
			if (start->GetCoef() == 0)
			{
				TMonom* temp = start->GetNext();
				delete[] start;
				start = temp;
			}
		}
		else
		{
			while (_end != 0)
			{
				if (*_end == mon)
				{
					*_end -= mon;
					if (_end->GetCoef() == 0)
					{
						start->SetNext(_end->GetNext());
						delete[] _end;
					}
					leng++;
					return *this;
				}
				if (*_end < mon)
				{
					TMonom* tmp = new TMonom(mon);
					_start->SetNext(tmp);
					tmp->SetNext(_end);
					leng++;
					return *this;
				}
				_start = _end;
				_end = _end->GetNext();
			}
			_start->SetNext(new TMonom(mon));
		}
	}
	leng++;
	return *this;
}

TPolynom TPolynom::operator*(TPolynom &pol)
{
	if (this->countVar != pol.countVar)
		throw MyException("Error different polinomial`s count");
	TPolynom res(countVar);
	TMonom *_st = start;
	TMonom *_pst = pol.start;
	while (_st != 0)
	{
		if (_st->GetCoef() == 0)
			continue;
		while (_pst != 0)
		{
			if (_pst->GetCoef() == 0)
				continue;
			TMonom k = (*_st);
			k *= (*_pst);
			TMonom* f = new TMonom(k);
			f->SetNext(NULL);
			res += *f;
			_pst = _pst->GetNext();
		}
		_st = _st->GetNext();
		_pst = pol.start;
	}
	return res;
}


TPolynom& TPolynom::operator=(const TPolynom &pol)
{
  if (this == &pol)
    return *this;
  if (this->countVar != pol.countVar)
    throw MyException("Error different polinomial`s count");
  else
  {
    leng = pol.leng;
    TMonom *buf1 = start, *buf2 = start;
    while (buf1 != 0)
    {
      buf1 = buf1->GetNext();
      delete buf2;
      buf2 = buf1;
    }
    buf1 = pol.start->GetNext();
    buf2 = new TMonom(*pol.start);
    start = buf2;
    while (buf1 != 0)
    {
      buf2->SetNext(new TMonom(*buf1));
      buf2 = buf2->GetNext();
      buf1 = buf1->GetNext();
    }
    return *this;
  }
}

bool TPolynom::operator==(const TPolynom &pol)
{
  if (this->countVar != pol.countVar)
    throw MyException("Error different polinomial`s count");
  if (this->leng != pol.leng)
    return false;
  TMonom* tmon1 = start;
  TMonom* tmon2 = pol.start;
  while (tmon1 != 0)
  {
    if (!(*tmon1 == *tmon2))
      return false;
    if (tmon1->GetCoef() != tmon2->GetCoef())
      return false;
    tmon1 = tmon1->GetNext();
    tmon2 = tmon2->GetNext();
  }
  return true;
}

ostream& operator<<(ostream& ostr, TPolynom& pol)
{
  TMonom *tmp = pol.start;
  if (tmp != 0)
  {
    ostr << *tmp;
    tmp = tmp->GetNext();
  }
  while (tmp != 0)
  {
    if (tmp->GetCoef() != 0)
      ostr << " + " << *tmp;
    tmp = tmp->GetNext();
  }
  return ostr;
}

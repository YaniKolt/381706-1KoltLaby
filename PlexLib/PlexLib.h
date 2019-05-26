#pragma once
#include "PointLib.h"
#include "SectionLib.h"
#include "ExceptionLib.h"

#include <iostream>
#include <locale>

using namespace std;


class TPlex: public TPoint
{
protected:
  TPoint *l, *r;                        //��������� �� ����� � ������ ����� ������

public:

	TPlex();                              //����������� �� ���������
  TPlex (TPoint *_l, TPoint *_r);       //����������� �������������
  TPlex (TPlex& P);                     //����������� �����������

  void SetL (TPoint *_l);               //������ ����� �����
  void SetR (TPoint *_r);               //������ ������ �����
  TPoint* GetL();                       //�������� ����� �����
  TPoint* GetR();                       //�������� ������ �����

	virtual void show();

  void Add (TPoint *_p1, TPoint *_p2);   //�������� ����� � �����
	TPoint* Search(TPoint *point);         //����� �����

};


void TPlex::SetL(TPoint* _l)
{
  l = _l;
}

void TPlex::SetR(TPoint* _r)
{
  r = _r;
}

TPoint* TPlex::GetL()
{
  return l;
}

TPoint* TPlex::GetR()
{
  return r;
}

TPlex::TPlex()
{
	l = NULL;
	r = NULL;
}

TPlex::TPlex(TPoint *_l, TPoint *_r)
{
  l = _l;
	r = _r;
}


TPlex::TPlex(TPlex& P)
{
  TPlex *pl, *pr;
	pl = dynamic_cast <TPlex*> (P.l);
	pr = dynamic_cast <TPlex*> (P.r);
	if (pl != 0)
		l = new TPlex(*pl);
	else
		l = new TPoint(*(P.GetL()));
	if (pr != 0)
		r = new TPlex(*pr);
	else
		r = new TPoint(*(P.GetR()));
}

TPoint* TPlex::Search(TPoint *point)
{
	TPlex *pl, *pr;
	TPoint* res;
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	if (*l == *point) 
		return l;	
	else if (pl != NULL)
	{
		res = pl->Search(point);
		if (res != NULL)
			return res;
	}
	if (*r == *point) 
		return r;	
	else if (pr != NULL)
	{
		pr->Search(point);
		if (res != NULL)
			return res;
	}
	if ((pr == NULL)&&(pl == NULL))
		return NULL;
}

void TPlex::Add(TPoint* p1, TPoint* p2)
{

	TPlex *pl, *pr;
	TPoint* res;
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	
	if ((pl == 0) && ((*l == *p1) || (*l == *p2)))
		{
			l = new TPlex(p1, p2);
		}
	else if ((pr == 0) && ((*r == *p1) || (*r == *p2)))
		{
			r = new TPlex(p1, p2);
		}
	else if (pl != 0)
		{
			pl->Add(p1, p2);
		}
	else if (pr != 0)
		{
			pr->Add(p1, p2);
		}
	else
		throw MyException("��� ����� ����� � ������");;
	


}

void TPlex::show()
{
	TPlex *pl, *pr;
	cout<<"�������  \n";
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	if (pl != 0)
	{
		cout<<"����� ";
		pl->show();
	}
	else if (pl == 0)
	{
		cout<<"����� �����:\n";
		l->show();
	}
	if (pr != 0)
	{
		cout<<"������ ";
		pr->show();
	}
	else if (pr == 0)
	{
		cout<<"������ �����:\n";
		r->show();
	}
}
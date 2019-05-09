#pragma once
#include <iostream>

using namespace std;


class TSection
{
protected:
	TPoint p1, p2;                             //Точки на концах отрезка

public:
	TSection(TPoint _p1, TPoint _p2);          //Конструктор инициализатор       
	TSection(TSection &S);                     //Конструктор копирования

	void SetP1(TPoint _p);                     //Задать точку р1
	void SetP2(TPoint _p);                     //Задать точку р2
	TPoint GetP1();                            //Получить точку р1
	TPoint GetP2();                            //Получить точку р2


	virtual void show();

};


void TSection::SetP1(TPoint _p)
{
	p1 = _p;
}

void TSection::SetP2(TPoint _p)
{
	p2 = _p;
}

TPoint TSection::GetP1()
{
	return p1;
}

TPoint TSection::GetP2()
{
	return p2;
}

TSection::TSection(TPoint _p1, TPoint _p2)
{
	p1 = _p1;
	p2 = _p2;
}

TSection::TSection(TSection &S)
{
	p1 = S.p1;
	p2 = S.p2;
}

void TSection::show()
{
	cout <<"("<< p1.GetX() << "," << p1.GetY() << ")\n(" << p2.GetX() << "," << p2.GetY() << ")\n";
}

#pragma once
#include <iostream>

using namespace std;


class TPoint
{
protected:
	double x, y;

 public:

  TPoint (double _x = 0, double _y = 0);  //Конструктор инициализатор
  TPoint (TPoint &point);                 //Конструктор копирования

  void SetX(double _x);                   //Задать координату Х
  void SetY(double _y);                   //Задать координату У

  double GetX();                          //Получить координату Х
  double GetY();                          //Получить координату У

	virtual void show();                    //Вывести на экран

	bool operator == (TPoint &point);       //Сравнение на равенство
	TPoint& operator = (TPoint &point);     //Оператор присваивания
};

void TPoint::SetX(double _x)
{
  x = _x;
}

void TPoint::SetY(double _y)
{
 y = _y;
}

double TPoint::GetX()
{
  return x;
}

double TPoint::GetY()
{
  return y;
}

TPoint::TPoint (double _x, double _y)
{
  x = _x;
  y = _y;
}

TPoint::TPoint(TPoint &point)
{
  x = point.x;
  y = point.y;
}

void TPoint::show()
{
	cout<<"("<<x<<","<<y<<")\n";
}

bool TPoint::operator == (TPoint &point)
{
	return ((x == point.GetX())&&(y == point.GetY()));
}

TPoint& TPoint::operator = (TPoint &point)
{
	x = point.x;
	y = point.y;
	return *this;
}
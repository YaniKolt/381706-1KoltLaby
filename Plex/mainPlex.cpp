
#include "PlexLib.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
  setlocale (LC_ALL, "Russian");

	int _p1 = 0, _p2 = 0;
	TPoint Point1, Point2(2,4), Point3(0,5), Point4(4,13), Point5;
	cout<<"Введите первую точку:\n";
	cin>>_p1>>_p2;
	//cout<<":\n";
	Point1.SetX(_p1);
	Point1.SetY(_p2);
	Point1.show();
	cout<<"Координаты второй и третьей точек:\n";
	Point2.show();
	Point3.show();
	cout<<"\n\n\n";
	
	cout<<"Отрезки:\n";
	TSection Po1Po2(Point1, Point2);
	cout<<"Отрезок из первых двух точек имеет координты:\n";
	Po1Po2.show();
	cout<<"\n\n\n";

	cout<<"Плексы:\n";
	TPlex P, P1(&Point1, &Point2);
	TPlex P2(P1);
	cout<<"Был создан плекс из первой и второй точек\n";
	cout<<"Добавление в плекс третьей точки с координатами (0, 5)\n";
	P2.Add(&Point1, &Point3);
	cout<<"Добавление в плекс четвертой точки с координатами  (4, 13)\n";
	P2.Add(&Point3, &Point4);
	
	cout<<"Введите пятую точку:\n";
	cin>>_p1>>_p2;
	cout<<"В плекс добавлена введенная точка \n";
	Point5.SetX(_p1);
	Point5.SetY(_p2);
	P2.Add(&Point2,&Point5);
	cout<<"Полученный плекс: \n";
	P2.show();
	cout<<"\n\n\n";
  
	return 0;
}

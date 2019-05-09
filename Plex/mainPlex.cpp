
#include "PlexLib.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
  setlocale (LC_ALL, "Russian");

	int _p1 = 0, _p2 = 0;
	TPoint Point1, Point2(2,4), Point3(0,5), Point4(4,13), Point5;
	cout<<"������� ������ �����:\n";
	cin>>_p1>>_p2;
	//cout<<":\n";
	Point1.SetX(_p1);
	Point1.SetY(_p2);
	Point1.show();
	cout<<"���������� ������ � ������� �����:\n";
	Point2.show();
	Point3.show();
	cout<<"\n\n\n";
	
	cout<<"�������:\n";
	TSection Po1Po2(Point1, Point2);
	cout<<"������� �� ������ ���� ����� ����� ���������:\n";
	Po1Po2.show();
	cout<<"\n\n\n";

	cout<<"������:\n";
	TPlex P, P1(&Point1, &Point2);
	TPlex P2(P1);
	cout<<"��� ������ ����� �� ������ � ������ �����\n";
	cout<<"���������� � ����� ������� ����� � ������������ (0, 5)\n";
	P2.Add(&Point1, &Point3);
	cout<<"���������� � ����� ��������� ����� � ������������  (4, 13)\n";
	P2.Add(&Point3, &Point4);
	
	cout<<"������� ����� �����:\n";
	cin>>_p1>>_p2;
	cout<<"� ����� ��������� ��������� ����� \n";
	Point5.SetX(_p1);
	Point5.SetY(_p2);
	P2.Add(&Point2,&Point5);
	cout<<"���������� �����: \n";
	P2.show();
	cout<<"\n\n\n";
  
	return 0;
}

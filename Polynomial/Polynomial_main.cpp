#include "Polynomial.h"
#include <ctime>

int main() 
{
	setlocale(LC_ALL, "Russian");
	try
	{
		cout << "Зададим трехпеременные мономы,в ходе работы с которыми создадим полиномы:\n";

		int deg1[] = { 4, 2, 5 };
		int deg2[] = { 9, 0, 2 };
		int deg3[] = { 0, 1, 0 };
		int deg4[] = { 4, 2, 5 };
		int deg5[] = { 19, 27, 63 };
		int deg6[] = { 6, 2, 10 };

		TMonom mon1(3, deg1, 13);
		TMonom mon2(3, deg2, 2);
		TMonom mon3(3, deg3, 4);
		TMonom mon4(3, deg4, 3);
		TMonom mon5(3, deg5, 0);
		TMonom mon6(3, deg6, 1);

		cout << "1) Первый моном: " << mon1 << endl;
		cout << "2) Второй моном: " << mon2 << endl;
		cout << "3) Третий моном: " << mon3 << endl;
		cout << "4) Четвертый моном: " << mon4 << endl;
		cout << "5) Пятый моном: " << mon5 << endl;
		cout << "6) Шестой моном: " << mon6 << endl;


		TPolynom pol1(3);
		pol1 += mon1;
		pol1 += mon2;
		pol1 += mon3;
		cout << "\nI) Первый полином, составленный из 1), 2) и 3) мономов = " << pol1 << endl;

		TPolynom pol2(3);
		pol2 += mon4;
		pol2 += mon5;
		pol2 += mon6;
		cout << "II) Второй полином, составленный из 4), 5) и 6) мономов = " << pol2 << endl;

		cout << "\nСтандартные арифметические операции:\n";

		TPolynom respol(3);

		respol = pol1 + pol2;
		cout << "Сумма полиномов I) и II):\n" << respol << endl;

		respol = pol1 - pol2;
		cout << "\nРазность полиномов I) и II)\n" << respol << endl;

		respol = pol1 * pol2;
		cout << "\nПроизведение полиномов I) и II)\n" << respol << endl;

		cout << "\nРассмотрим полином, полученный операцией умножения поподробнее:\n";

		cout << "Он состоит из " << respol.GetLeng() << " мономов\n";

		cout << "Первый из которых: " << *respol.GetStart() << endl;

		cout << "Сравним его с полиномом I): ";
		if (respol == pol1)
			cout << "Полиномы равны";
		else
			cout << "Полинмы не равны";

		respol = pol2;
		cout << "\nПриравняв этот полином к II), мы получим: " << respol << endl;
	}

	catch (MyException exc)
	{
		exc.Print();
	}
 return 0;
}

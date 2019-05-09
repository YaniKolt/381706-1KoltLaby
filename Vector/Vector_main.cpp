#include "Vector.h" 
#include <cstdlib> 
#include <ctime> 

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(static_cast<unsigned int>(time(0)));
	double ra, nd, om;

	cout << "Вектора:\n";
	TVector <int> a(3), b(3), c(3);
	for (int i = 0; i < 3; i++)
	{
		ra = rand();
		nd = ra / RAND_MAX;
		om = nd * 49 + 1;

		a[i] = om;

		ra = rand();
		nd = ra / RAND_MAX;
		om = nd * 49 + 1;

		b[i] = om;
	}
  cout << "\n\nA: " << a << endl;
  cout << "B: " << b << endl;

  cout << "\n\nАрифметические операции:\n\n";
  try 
  {
    c = a + b;
    cout << "A + B: " << c << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try 
  {
    c = a - b;
    cout << "A - B: " << c << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try 
  {
    int k = a * b;
    cout << "A * B: " << k << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  cout << "\n\nПользовательский ввод и вывод:\n";
  TVector <int> v(4);
  cin >> v;
  cout << "\nВведите вектор: " << v << endl;
  return 0;
}

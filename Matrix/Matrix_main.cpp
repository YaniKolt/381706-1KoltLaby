#include "Matrix.h" 
#include <cstdlib> 
#include <iomanip> 
#include <ctime> 

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(static_cast<unsigned int>(time(0)));
	double ra, nd, om;

	cout<< "Матрицы: \n";
	TMatrix<double> a(5), b(5), c(5);
	TMatrix<double> MDel(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i; j++)
		{
			ra = rand();
			nd = ra / RAND_MAX;
			om = nd * 49 + 1;

			a[i][j] = om;

			ra = rand();
			nd = ra / RAND_MAX;
			om = nd * 49 + 1;

			b[i][j] = om;
		}
  cout << "A: \n" << endl << a << endl;
  cout << "\nB: \n" << endl << b << endl;

  cout << "Арифметические операции: \n\n";
  try {
    c = a + b;
    cout << "A + B = \n" << c << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try {
    c = a - b;
    cout << "A - B = \n"  << c << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try {
    c = a * b;
    cout << "A * B = \n"<< c << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  cout << "\n\nПользовательский ввод / output streams:\n";
  TMatrix <int> mt(3);
  cin >> mt;
  cout << "\nВведите матрицу: \n" << endl << mt;
  return 0;
}

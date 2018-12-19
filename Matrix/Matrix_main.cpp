#include "Matrix.h" 
#include <cstdlib> 
#include <iomanip> 
#include <ctime> 

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(static_cast<unsigned int>(time(0)));
	double ra, nd, om;

	cout << "Матрицы: \n";
	TMatrix<double> A(5), B(5), C(5);
	TMatrix<double> MDEL(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i; j++)
		{
			ra = rand();
			nd = ra / RAND_MAX;
			om = nd * 49 + 1;

			A[i][j] = om;

			ra = rand();
			nd = ra / RAND_MAX;
			om = nd * 49 + 1;

			B[i][j] = om;
		}
  cout << "A:" << endl << A << endl;
  cout << "\nB:" << endl << B << endl;

  cout << "Arithmetic operations: \n\n";
  try {
    C = A + B;
    cout << "A + B = \n" << C << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try {
    C = A - B;
    cout << "A - B = \n"  << C << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try {
    C = A * B;
    cout << "A * B = \n"<< C << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

	try {
		MDEL = A / B;
		cout << "Матрица 1 / Матрица 2: " << endl << MDEL << endl;
	}
	catch (MyException exp)
	{
		exp.Print();
	}

  cout << "\n\nUsing input / output streams:\n";
  TMatrix <int> MT(3);
  cin >> MT;
  cout << "\nMatrix entered by youself:" << endl << MT;
  return 0;
}

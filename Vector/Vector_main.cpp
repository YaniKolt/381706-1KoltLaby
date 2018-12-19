#include "Vector.h" 
#include <cstdlib> 
#include <ctime> 

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(static_cast<unsigned int>(time(0)));
	double ra, nd, om;

	cout << "Вектора:\n";
	TVector <int> A(3), B(3), C(3);
	for (int i = 0; i < 3; i++)
	{
		ra = rand();
		nd = ra / RAND_MAX;
		om = nd * 49 + 1;

		A[i] = om;

		ra = rand();
		nd = ra / RAND_MAX;
		om = nd * 49 + 1;

		B[i] = om;
	}

  cout << "\n\nA: " << A << endl;
  cout << "B: " << B << endl;

  cout << "\n\nArithmetic operations:\n\n";
  try 
  {
    C = A + B;
    cout << "Result A + B: " << C << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try 
  {
    C = A - B;
    cout << "Result A - B: " << C << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try 
  {
    int k = A * B;
    cout << "Result A * B: " << k << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  cout << "\n\nUsing input / output streams:\n";
  TVector <int> V(4);
  cin >> V;
  cout << "\nVector entered by you: " << V << endl;
  return 0;
}

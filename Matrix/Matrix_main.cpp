#include "Matrix.h"

int main()
{
  cout << "Creating matrix\n\n";
  TMatrix<int> A(3), B(3), C(3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3 - i; j++) 
    {
      A[i][j] = (10 * i) + (6 * j + 1);
      B[i][j] = ((i + 5) * j + 3 + i) * 8;
    }
  cout << "A:" << endl << A << endl;
  cout << "\nB:" << endl << B << endl;

  cout << "Arithmetic operations: \n\n";
  try {
    C = A + B;
    cout << "A + B = " << C << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try {
    C = A - B;
    cout << "A - B = "  << C << endl;
  }
  catch (MyException exp)
  {
    exp.Print();
  }

  try {
    C = A * B;
    cout << "A * B = "<< C << endl;
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
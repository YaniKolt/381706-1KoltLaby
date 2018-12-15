#include "Vector.h"

int main()
{
  cout << "Vectors:";
  TVector <int> A(3), B(3), C(3);
  for (int i = 0; i < 3; i++)
  {
    A[i] = (i - 5 + (i - 7) * 2);
    B[i] = (i - 13 + 3*i) * 2;
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

 // cout << "\n\nUsing input / output streams:\n";
  //TVector <int> V(4);
  //cin >> V;
  //cout << "\nVector entered by you: " << V << endl;
  return 0;
}

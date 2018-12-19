#include <iostream>
#include"Queue.h"
using namespace std;

int main ()
{  

	setlocale(LC_ALL, "Russian");

	TQueue<int> A(8);
	A.Put(7);
	A.Put(4);
	A.Put(3);
	cout << "Get_1:" << A.Get() << endl;
	cout << "Get_2:" << A.Get() << endl;

	return 0;
}
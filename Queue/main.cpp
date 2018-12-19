#include <iostream>
#include"Queue.h"
using namespace std;

int main ()
{  
	TQueue<int> A(10);
	A.Put(43);
	A.Put(42);
	A.Put(41);
	cout << "Get1:" << A.Get() << endl;
	cout << "Get2:" << A.Get() << endl;

	return 0;
}
#include "Polish.h"

int  main()
{
	setlocale(LC_ALL, "Russian");

  try
  {
		cout << "Перевод и счет математического выражения, переведенного в обратную польскую запись \n";
    cout << "Введите математическое выражение";
    TString str;
    cin >> str;

    cout << str << " Оно же в обратной польской записи: ";
    TQueue<char> que;

    que = ConvertToPol(str);
    que.Print();

    cout << " = " << Res(que) << endl;
  }
  
  catch (MyException exc)
  {
    exc.Print();
  }
  return 0;
}

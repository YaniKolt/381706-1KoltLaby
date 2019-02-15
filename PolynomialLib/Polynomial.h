#pragma once
#include "Monom.h"

class TPolynom
{
protected:
  TMonom *start;																	//указатель на начальный моном в полиноме
  int countVar;																	  //количество переменных в каждом мономе
  int leng;																				//количество мономов в полиноме 
public:
  TPolynom(int _count = 3);
  TPolynom(TPolynom &pol);
  ~TPolynom();

  int GetLeng();																	//получить число мономов в полиноме
  TMonom* GetStart();															//получить адрес первого монома в полиноме

  TPolynom operator+(TPolynom &pol);
  TPolynom& operator+=(TMonom &mon);

	TPolynom operator-(TPolynom &pol);
  TPolynom& operator-=(TMonom &mon);

	TPolynom operator*(TPolynom &pol);

	TPolynom& operator=(const TPolynom &pol);
	bool operator==(const TPolynom &pol);

  friend std::ostream& operator<<(std::ostream& ostr, TPolynom& pol);
};


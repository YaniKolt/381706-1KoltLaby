#include "Stroka.h"
#include <string.h>

TString::TString()
{
	strg = 0;
	leng = 0;
}

TString::TString(TString &str)
{
	leng = str.leng;
	if (leng != 0)
	{
		strg = new char[leng];
		for (int i = 0; i < leng; i++)
			strg[i] = str.strg[i];
	}
	else
		strg = 0;
}

TString::TString(char* _string) 
{
  if (_string == 0)
    throw MyException("Error String is Empty");

  if (_string[0] == '\0')
    return;

  leng = strlen(_string) + 1; 
  strg = new char[leng];
  for (int i = 0; i < leng - 1; i++)
    strg[i] = _string[i];
  strg[leng - 1] = 0;
}

TString::~TString()
{
	if (strg != 0)
		delete [] strg;
}

int TString::GetLeng()
{
	return leng;
}

void TString::DeleteStrg()
{
	*strg = '\0';
	leng = 0;
}

TString TString::operator+(TString &str)
{
	TString temp;
	temp.leng = leng + str.leng - 1;
	temp.strg = new char[temp.leng];
	for (int i = 0; i < leng - 1; i++)
	{
		temp.strg[i] = strg[i];
	}
	for (int i = leng - 1; i < temp.leng; i++)
	{
		temp.strg[i] = str.strg[i - (leng - 1)];
	}
	return temp;
}

TString& TString::operator=(TString &str)
{
	if (this != &str)
	{
		leng = str.leng;
		if (leng != 0)
		{
			if (strg != 0)
				delete[]strg;
			strg = new char[str.leng];
			for (int i = 0; i < str.leng; i++)
			{
				strg[i] = str.strg[i];
			}
		}
		else
		{
			if (strg != 0)
				delete[]strg;
			strg = 0;
		}
	}
	return *this;
}

char& TString::operator[](int i)
{
  if ((i >= 0) && (i < leng))
    return strg[i];
  throw MyException("Error index");
}

std::istream& operator>>(std::istream &istr, TString &str)
{
	char s[256] = {0};
	istr >> s;

	str.leng = strlen(s) + 1;
	str.strg = new char[str.leng];
	for (int i = 0; i < str.leng - 1; i++)
	{
		str.strg[i] = s[i];
	}
	str.strg[str.leng - 1] = 0;
	return istr;
}

std::ostream& operator<<(std::ostream &ostr, const TString &str)
{
	ostr << str.strg;
	return ostr;
}
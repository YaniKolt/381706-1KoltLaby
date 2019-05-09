#pragma once
#include "Queue.h"
#include "Stroka.h"

int GetPriority(const char prior);

TQueue<char> ConvertToPol(TString str);

double Res(TQueue<char> que);

bool IsPolish(char s);

#pragma once
#include "../QueueLib/Queue.h"
#include "Stroka.h"

int GetPriority(const char prior);

Queue<char> ConvertToPol(TString str);

double Res(Queue<char> que);

bool IsPolish(char s);

#pragma once
#include "Monom.h"

class TPolynom
{
protected:
  TMonom *begin;																		//указатель на первый моном в полиноме
  int count;																			 //количество переменных в каждом мономе
  int size;																				//количество мономов в полиноме 
public:
  TPolynom(int _count = 3);
  TPolynom(TPolynom &pol);
  ~TPolynom();

  int GetSize();																	//получить число мономов в полиноме
  TMonom* GetBegin();															//получить адрес первого монома в полиноме

  TPolynom operator+(TPolynom &pol);
  TPolynom& operator+=(TMonom &mon);

	TPolynom operator-(TPolynom &pol);
  TPolynom& operator-=(TMonom &mon);

	TPolynom operator*(TPolynom &pol);

	TPolynom& operator=(const TPolynom &pol);
	bool operator==(const TPolynom &pol);

  friend std::ostream& operator<<(std::ostream& ostr, TPolynom& pol);
};


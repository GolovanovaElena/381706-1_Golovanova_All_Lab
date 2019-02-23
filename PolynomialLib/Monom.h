#pragma once
#include "Exception.h"

class TMonom
{
protected:
  TMonom* next;																	//указатель на следующий моном
  int *deg;																		  //массив степеней
  double coef;																	//коэффициент
  int count;																		//количество переменных в мономе

public:
  TMonom();
  TMonom(int _count, int* _deg, double _coef);
  TMonom(const TMonom& mon);
  virtual ~TMonom();

	void SetNext(TMonom* _next);                  //задать адрес следующего монома
	void SetDeg(int* _deg);											//задать массив степеней монома
	void SetCoef(double _coef);									//задать коэффициент при мономе
	void SetCount(int _count);									//задать количество переменных в мономе

  TMonom* GetNext();														//получить адрес следующего монома
  int* GetDeg();															//получить массив степеней монома
  double GetCoef();														//получить коэффициент при мономе
  int GetCount();															//получить количество переменных в мономе

  TMonom operator+(TMonom& mon);
  TMonom operator+=(TMonom& mon);

	TMonom operator-(TMonom& mon);
	TMonom operator-=(TMonom& mon);

  TMonom operator*(const TMonom& mon) const;
  TMonom operator*=(TMonom& mon);

	TMonom& operator=(const TMonom& mon);
  bool operator==(TMonom& mon);
  bool operator>(TMonom& mon);
  bool operator<(TMonom& mon);

  friend istream& operator>>(istream& istr, TMonom& mon);
  friend ostream& operator<<(ostream& ostr, TMonom& mon);
};

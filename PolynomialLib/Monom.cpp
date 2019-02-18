#include "Monom.h"

TMonom::TMonom()
{
  next = NULL;
  deg = NULL;
  coef = 0;
  count = 0;
}

TMonom::TMonom(int _count, int* _deg, double _coef)
{
  if (_count < 0)
    throw TException("Error count");

  else if (_count == 0)
  {
    deg = NULL;
    count = _count;
    coef = _coef;
    next = NULL;
  }
  else
  {
    count = _count;
    coef = _coef;
    next = NULL;
    deg = new int[_count];
    for (int i = 0; i < _count; i++)
    {
      if (_deg[i] >= 0)
        deg[i] = _deg[i];
      else
        throw TException("Error deg");
    }
  }
}


TMonom::TMonom(const TMonom &mon)
{
  count = mon.count;
  coef = mon.coef;
  next = mon.next;
  deg = new int[count];
  for (int i = 0; i < count; i++)
  {
    deg[i] = mon.deg[i];
  }
}


TMonom::~TMonom()
{
  if (deg != 0)
    delete[]deg;
  count = 0;
  coef = 0;
  next = 0;
}


TMonom* TMonom::GetNext()
{
  return next;
}


int* TMonom::GetDeg()
{
  return deg;
}


double TMonom::GetCoef()
{
  return coef;
}


int TMonom::GetCount()
{
  return count;
}


void TMonom::SetNext(TMonom* _next)
{
  next = _next;
}


void TMonom::SetDeg(int* _deg)
{
  for (int i = 0; i < count; i++)
  {
    if (_deg[i] >= 0)
      deg[i] = _deg[i];
    else
      throw TException("Error deg");
  }
}


void TMonom::SetCoef(double _coef)
{
  coef = _coef;
}


void TMonom::SetCount(int _count)
{
  if (_count < 0)
    throw TException("Error count");

  else if (_count == 0)
  {
    if (deg != 0)
      delete[] deg;
    deg = 0;
    count = 0;
  }
  else
  {
    int *tmp = new int[count];
    for (int i = 0; i < count; i++)
      tmp[i] = deg[i];
    delete[]deg;
    deg = new int[_count];
    int i = 0;
    if (count < _count)
    {
      for (; i < count; i++)
        deg[i] = tmp[i];
      for (; i < _count; i++)
        deg[i] = 0;
    }
    if (_count < count)
      for (; i < _count; i++)
        deg[i] = tmp[i];
    count = _count;
  }
}


TMonom TMonom::operator+(TMonom& mon)
{
  TMonom tmp(mon);
  if (count != mon.count)
    throw TException("Error Different count");

	for (int i = 0; i < mon.count; i++)
		if (deg[i] != mon.deg[i])
    throw TException("Error Different deg");

  tmp.coef = coef + mon.coef;
  return tmp;
}


TMonom TMonom::operator+=(TMonom & mon)
{
  if (count != mon.count)
    throw TException("Error Different count");

	for (int i = 0; i < mon.count; i++)
		if (deg[i] != mon.deg[i])
    throw TException("Error Different deg");

  coef += mon.coef;
  return *this;
}


TMonom TMonom::operator-(TMonom& mon)
{
  TMonom tmp(mon);
  if (count != mon.count)
    throw TException("Error Different count");

	for (int i =0; i<mon.count; i++)
  if (deg[i]!=mon.deg[i])
    throw TException("Error Different deg");

  tmp.coef = coef - mon.coef;
  return tmp;
}


TMonom TMonom::operator-=(TMonom & mon)
{
  if (count != mon.count)
    throw TException("Error Different count");

	for (int i = 0; i < mon.count; i++)
		if (deg[i] != mon.deg[i])
    throw TException("Error Different deg");

  coef -= mon.coef;
  return *this;
}


TMonom TMonom::operator*(const TMonom& mon) const
{
  if (count != mon.count)
    throw TException("Error Different count");

  TMonom tmp(mon);
  tmp.coef = coef * mon.coef;
  for (int i = 0; i < count; i++)
    tmp.deg[i] = deg[i] + mon.deg[i];
  return tmp;
}


TMonom TMonom::operator*=(TMonom& mon)
{
  if (count != mon.count)
    throw TException("Error Different count");

  coef = coef * mon.coef;
  for (int i = 0; i < count; i++)
    deg[i] += mon.deg[i];
  return *this;
}


TMonom& TMonom::operator=(const TMonom& mon)
{
	if (count != mon.count)
		throw TException("Error size not equal");

	coef = mon.coef;
	count = mon.count;
	next = mon.next;
	delete[] deg;
	deg = new int[count];
	for (int i = 0; i < count; i++)
		deg[i] = mon.deg[i];
	return *this;
}


bool TMonom::operator==(TMonom& mon)
{
  if (count != mon.count)
    throw TException("Error Different count");
	for (int i = 0; i < count; i++)
		if (deg[i] != mon.deg[i])
			return false;
  return true;
}


bool TMonom::operator>(TMonom& mon)
{
  if (count != mon.count)
    throw TException("Error Different count");

  if (*this == mon)
    throw TException("Error Monoms are equal");

  for (int i = 0; i < count; i++)
  {
    if (deg[i] == mon.deg[i])
      continue;
    else if (deg[i] > mon.deg[i])
      return true;
    else
      return false;
  }
	if (coef < mon.coef)
		return false;
  return true;
}


bool TMonom::operator<(TMonom& mon)
{
  if (count != mon.count)
    throw TException("Error Different count");

  if (*this == mon)
    throw TException("Monoms are equal");

  for (int i = 0; i < count; i++)
  {
    if (deg[i] == mon.deg[i])
      continue;
    else if (deg[i] < mon.deg[i])
      return true;
    else
      return false;
  }
  if (coef > mon.coef)
    return false;
  return true;
}


istream& operator>>(istream& istr, TMonom& mon)
{
  istr >> mon.coef;
  for (int i = 0; i < mon.count; i++)
    istr >> mon.deg[i];
  return istr;
}


ostream& operator<<(ostream& ostr, TMonom& mon)
{
  ostr << mon.coef;
  if (mon.coef != 0)
  {
    for (int i = 0; i < mon.count; i++)
      if (mon.deg[i] != 0)
      {
        ostr << "*x" << i;
        if (mon.deg[i] != 1)
          ostr << "^" << mon.deg[i];
      }
  }
  return ostr;
}

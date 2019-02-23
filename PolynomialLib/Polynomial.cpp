#include "Polynomial.h"


TPolynom::TPolynom(int _count)
{
  if (_count <= 0)
    throw TException("Error count");
  count = _count;
  size = 0;
  begin = 0;
}


TPolynom::TPolynom(TPolynom &pol)
{
  count = pol.count;
  size = pol.size;
  if (pol.begin == 0)
    begin = 0;
  else
  {
    begin = new TMonom(*pol.begin);
    TMonom* tmon1 = pol.begin;
    TMonom* tmon2 = begin;
    while (tmon1->GetNext() != 0)
    {
      tmon2->SetNext(new TMonom(*(tmon1->GetNext())));
      tmon2 = tmon2->GetNext();
      tmon1 = tmon1->GetNext();
    }
    tmon2->SetNext(NULL);
  }
}


TPolynom::~TPolynom()
{
}


int TPolynom::GetSize()
{
  return size;
}

TMonom* TPolynom::GetBegin()
{
  return begin;
}

TPolynom TPolynom::operator+(TPolynom &pol)
{
  if (this->count != pol.count)
    throw TException("Error Different count");

  TPolynom res(count);
  TMonom *tmon1 = begin, *tmon2 = pol.begin, *tmon = res.begin;
  while ((tmon1 != 0) && (tmon2 != 0))
  {
    TMonom *t;
    if ((*tmon1) == (*tmon2))
    {
      TMonom k = (*tmon1);
      k += (*tmon2);
      t = new TMonom(k);
      if (t->GetCoef() == 0)
        continue;
      tmon1 = tmon1->GetNext();
      tmon2 = tmon2->GetNext();
    }
    else if ((*tmon1) < (*tmon2))
    {
      t = new TMonom((*tmon2));
      if (t->GetCoef() == 0)
        continue;
      tmon2 = tmon2->GetNext();
    }
    else if ((*tmon1) > (*tmon2))
    {
      t = new TMonom((*tmon1));
      if (t->GetCoef() == 0)
        continue;
      tmon1 = tmon1->GetNext();
    }
    if (tmon == 0)
    {
      tmon = t;
      res.begin = t;
      res.size++;
    }
    else
    {
      tmon->SetNext(t);
      res.size++;
      tmon = tmon->GetNext();
    }
  }
  if (tmon1 == 0)
    tmon1 = tmon2;
  while (tmon1 != 0)
  {
    if (tmon1->GetCoef() == 0)
      continue;
    tmon->SetNext(new TMonom(*tmon1));
    tmon1 = tmon1->GetNext();
    res.size++;
    tmon = tmon->GetNext();
  }
  return res;
}

TPolynom &TPolynom::operator+=(TMonom &mon)
{
	if (this->count != mon.GetCount())
		throw TException("Error Different count");

	if (mon.GetCoef() == 0)
		return *this;
	if (begin == 0)
		begin = new TMonom(mon);
	else
	{
		TMonom *_start, *_end;
		_start = begin;
		_end = begin->GetNext();
		if (*begin < mon)
		{
			TMonom* tmp = new TMonom(mon);
			tmp->SetNext(begin);
			begin = tmp;
		}
		else if (*begin == mon)
		{
			*begin += mon;
			if (begin->GetCoef() == 0)
			{
				TMonom* temp = begin->GetNext();
				delete[] begin;
				begin = temp;
			}
		}
		else
		{
			while (_end != 0)
			{
				if (*_end == mon)
				{
					*_end += mon;
					if (_end->GetCoef() == 0)
					{
						begin->SetNext(_end->GetNext());
						delete[] _end;
					}
					// size++;
					return *this;
				}
				if (*_end < mon)
				{
					TMonom* tmp = new TMonom(mon);
					_start->SetNext(tmp);
					tmp->SetNext(_end);
					size++;
					return *this;
				}
				_start = _end;
				_end = _end->GetNext();
			}
			_start->SetNext(new TMonom(mon));
		}
	}
	size++;
	return *this;
}

TPolynom TPolynom::operator-(TPolynom &pol)
{
  if (this->count != pol.count)
    throw TException("Error Different count");

  TPolynom res(count);
  TMonom *tmon1 = begin, *tmon2 = pol.begin, *tmon = res.begin;
  while ((tmon1 != 0) && (tmon2 != 0))
  {
    TMonom *t;
    if ((*tmon1) == (*tmon2))
    {
      TMonom k = (*tmon1);
      k -= (*tmon2);
      t = new TMonom(k);
      tmon1 = tmon1->GetNext();
      tmon2 = tmon2->GetNext();
    }
    else if ((*tmon1) < (*tmon2))
    {
      t = new TMonom((*tmon2));
      if (t->GetCoef() == 0)
        continue;
      t->SetCoef(t->GetCoef() * (-1));
      tmon2 = tmon2->GetNext();
    }
    else if ((*tmon1) > (*tmon2))
    {
      t = new TMonom((*tmon1));
      if (t->GetCoef() == 0)
        continue;
      tmon1 = tmon1->GetNext();
    }
    if (t->GetCoef() == 0)
      continue;
    if (tmon == 0)
    {
      tmon = t;
      res.begin = t;
      res.size++;
    }
    else
    {
      tmon->SetNext(t);
      res.size++;
      tmon = tmon->GetNext();
    }
  }
  while (tmon1 != 0)
  {
    if (tmon1->GetCoef() == 0)
      continue;
    tmon->SetNext(new TMonom(*tmon1));
    tmon1 = tmon1->GetNext();
    res.size++;
    tmon = tmon->GetNext();
  }
  while (tmon2 != 0)
  {
    if (tmon2->GetCoef() == 0)
      continue;
    TMonom t(*tmon2);
    t.SetCoef(t.GetCoef() * (-1));
    tmon->SetNext(&t);
    tmon2 = tmon2->GetNext();
    res.size++;
    tmon = tmon->GetNext();
  }
  return res;
}

TPolynom &TPolynom::operator-=(TMonom &mon)
{
	if (this->count != mon.GetCount())
		throw TException("Error Different count");

	if (mon.GetCoef() == 0)
		return *this;
	mon.SetCoef(mon.GetCoef() * (-1));
	if (begin == 0)
		begin = new TMonom(mon);
	else
	{
		TMonom *_start, *_end;
		_start = begin;
		_end = begin->GetNext();
		if (*begin < mon)
		{
			TMonom* tmp = new TMonom(mon);
			tmp->SetNext(begin);
			begin = tmp;
		}
		else if (*begin == mon)
		{
			*begin -= mon;
			if (begin->GetCoef() == 0)
			{
				TMonom* temp = begin->GetNext();
				delete[] begin;
				begin = temp;
			}
		}
		else
		{
			while (_end != 0)
			{
				if (*_end == mon)
				{
					*_end -= mon;
					if (_end->GetCoef() == 0)
					{
						begin->SetNext(_end->GetNext());
						delete[] _end;
					}
					size++;
					return *this;
				}
				if (*_end < mon)
				{
					TMonom* tmp = new TMonom(mon);
					_start->SetNext(tmp);
					tmp->SetNext(_end);
					size++;
					return *this;
				}
				_start = _end;
				_end = _end->GetNext();
			}
			_start->SetNext(new TMonom(mon));
		}
	}
	size++;
	return *this;
}

TPolynom TPolynom::operator*(TPolynom &pol)
{
	if (this->count != pol.count)
		throw TException("Error Different count");
	TPolynom res(count);
	TMonom *_st = begin;
	TMonom *_pst = pol.begin;
	while (_st != 0)
	{
		if (_st->GetCoef() == 0)
			continue;
		while (_pst != 0)
		{
			if (_pst->GetCoef() == 0)
				continue;
			TMonom k = (*_st);
			k *= (*_pst);
			TMonom* f = new TMonom(k);
			f->SetNext(NULL);
			res += *f;
			_pst = _pst->GetNext();
		}
		_st = _st->GetNext();
		_pst = pol.begin;
	}
	return res;
}

TPolynom& TPolynom::operator=(const TPolynom &pol)
{
  if (this == &pol)
    return *this;
  if (this->count != pol.count)
    throw TException("Error Different count");
  else
  {
    size = pol.size;
    TMonom *buf1 = begin, *buf2 = begin;
    while (buf1 != 0)
    {
      buf1 = buf1->GetNext();
      delete buf2;
      buf2 = buf1;
    }
    buf1 = pol.begin->GetNext();
    buf2 = new TMonom(*pol.begin);
    begin = buf2;
    while (buf1 != 0)
    {
      buf2->SetNext(new TMonom(*buf1));
      buf2 = buf2->GetNext();
      buf1 = buf1->GetNext();
    }
    return *this;
  }
}

bool TPolynom::operator==(const TPolynom &pol)
{
  if (this->count != pol.count)
    throw TException("Error Different count");
  if (this->size != pol.size)
    return false;
  TMonom* tmon1 = begin;
  TMonom* tmon2 = pol.begin;
  while (tmon1 != 0)
  {
    if (!(*tmon1 == *tmon2))
      return false;
    if (tmon1->GetCoef() != tmon2->GetCoef())
      return false;
    tmon1 = tmon1->GetNext();
    tmon2 = tmon2->GetNext();
  }
  return true;
}

ostream& operator<<(ostream& ostr, TPolynom& pol)
{
  TMonom *tmp = pol.begin;
  if (tmp != 0)
  {
    ostr << *tmp;
    tmp = tmp->GetNext();
  }
  while (tmp != 0)
  {
    if (tmp->GetCoef() != 0)
      ostr << " + " << *tmp;
    tmp = tmp->GetNext();
  }
  return ostr;
}

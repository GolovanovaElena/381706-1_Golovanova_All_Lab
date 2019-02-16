#pragma once
#include "Elem.h"
#include "..//Exception/Exception.h"
#include <iostream>
using namespace std;

template <class T>
class TList
{
protected:
	TElem<T>* begin;            //указатель на элемент в начале списка
	int num;                    //кол-во элементов в списке 
public:
	TList();                    //конструктор по умолчанию
	TList(TList<T> &F);         //конструктор копирования
	virtual ~TList();           //деструктор
	int GetSize();              //получить кол-во элементов в листе
	void Put(int _n, T elem);   //установить элемент на позицию n в списке
	T Get(int _n);              //получить элемент из списка
	void PutBegin(T A);         //положить в начало 
	void PutEnd(T A);           //положить в конец 
	T GetBegin();               //получить элемент в начале списка 
	T GetEnd();                 //получить элемент в конце списка 
	bool IsFull();              //проверка на полноту 
	bool IsEmpty();             //проверка на пустоту 
	void Print();               //печать листа 
};

template <class T>
TList<T>::TList()
{
	begin = 0;
	num = 0;
}
template <class T>
TList<T>::TList(TList<T> &F)
{
	num = F.num;
	TElem<T>* a = F.begin;
	TElem<T>* b;
	if (F.begin == 0)
		begin = 0;
	else
	{
		begin = new TElem<T>(*F.begin);
		b = begin;
		while (a->GetNext() != 0)
		{
			b->SetNext(new TElem<T>(*(a->GetNext())));
			a = a->GetNext();
			b = b->GetNext();
		}
	}
}

template <class T>
TList<T>::~TList()
{
	while (begin != 0)
	{
		TElem<T>* temp = begin;
		begin = begin->GetNext();
		delete temp;
	}
}

template<class T>
int TList<T>::GetSize()
{
	return num;
}

template<class T>
void TList<T>::Put(int _n, T elem)
{
	if (this->IsFull())
		throw TException("List is full");
	if (_n < 1 || _n > num - 1)
		throw TException("Uncurrent index");
	else
	{
		int i = 0;
		TElem<T>* a = begin;
		while (i != _n - 1)
		{
			a = a->GetNext();
			i++;
		}
		TElem<T>* temp = new TElem<T>(elem, a->GetNext());
		a->SetNext(temp);
		num++;
	}
}

template<class T>
T TList<T>::Get(int _n)
{
	if (this->IsEmpty())
		throw TException("List is empty");
	if (_n < 1 || _n > num - 1)
		throw TException("Uncurrent index");
	else
	{
		int i = 0;
		num--;
		TElem<T>* a = begin;
		TElem<T>* b = begin->GetNext();
		while (i != _n - 1)
		{
			a = b;
			b = b->GetNext();
			i++;
		}
		T temp = b->GetDannyye();
		a->SetNext(b->GetNext());
		delete b;
		return temp;
	}
}

template <class T>
void TList<T>::PutBegin(T A)
{
	if (this->IsFull())
		throw TException("List is full");
	if (begin == 0)
	{
		TElem<T>* temp = new TElem<T>(A, 0);
		begin = temp;
	}
	else
	{
		TElem<T>* temp = new TElem <T>(A, begin);
		begin = temp;
	}
	num++;
}

template <class T>
void TList<T>::PutEnd(T A)
{
	if (this->IsFull())
		throw TException("List is full");
	if (begin != 0)
	{
		TElem<T>* a = begin;
		while (a->GetNext() != 0)
			a = a->GetNext();
		a->SetNext(new TElem <T>(A, 0));
	}
	else
		begin = new TElem<T>(A, 0);
	num++;
}

template <class T>
T TList<T>::GetBegin()
{
	if (IsEmpty())
		throw TException("List is empty!");
	else
	{
		TElem<T>* a = begin;
		T temp = begin->TElem<T>::GetDannyye();
		begin = begin->TElem<T>::GetNext();
		delete a;
		num--;
		return temp;
	}
}

template <class T>
T TList<T>::GetEnd()
{
	if (IsEmpty())
		throw TException("List is Empty!");
	else
	{
		num--;
		TElem<T>* a = begin;
		TElem<T>* b = begin->GetNext();
		if (b == 0)
		{
			T temp = a->TElem<T>::GetDannyye();
			delete a;
			begin = 0;
			return temp;
		}
		else
		{
			while (b->GetNext() != 0)
			{
				a = b;
				b = b->GetNext();
			}
			T temp = b->GetDannyye();
			delete b;
			a->SetNext(0);
			return temp;
		}
	}
}

template <class T>
bool TList<T>::IsFull()
{
	try
	{
		TElem<T>* a = new TElem<T>();
		if (a == NULL)
			return 1;
		else
		{
			delete a;
			return 0;
		}
	}
	catch (...)
	{
		return 0;
	}
	return true;
}

template <class T>
bool TList<T>::IsEmpty()
{
	if (begin == 0)
		return 1;
	return 0;
}

template<class T>
inline void TList<T>::Print()
{
	if (begin == 0)
		throw TException("List is Empty.");
	else
	{
		TElem<T>* a = begin;
		while (a->GetNext() != 0)
		{
			cout << a->GetDannyye() << " ";
			a = a->GetNext();
		}
		cout << a->GetDannyye() << " ";
	}

}
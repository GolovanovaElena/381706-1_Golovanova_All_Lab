#pragma once
#include <iostream>
#include "..//Exception/Exception.h"

using namespace std;

template <class T>

class TStack
{
protected:
	int size; //размер стека
	int top; //самый верхний элемент
	T *mas; //элементы стека
public:
	int Getsize(); //возвращает размер
	TStack(int n); //конструктор инициализации
	TStack(TStack<T> &S); //конструктор копирования
	T Get(); //возвращает элемент, расположенный на вершине стека
	T Top();
	virtual ~TStack();
	void Put(T A); //положить элемент
	bool IsFull(); //проверка на полноту
	bool IsEmpty(); //проверка на пустоту
	void PrintStack(); //вывод стека
	int operator!=(const TStack<T>& stack) const; //проверка на неравенство
	int operator==(const TStack<T>& stack) const; //проверка на равенство
	TStack& operator=(const TStack<T>& stack); //приравнивание
};

template <class T>
int TStack<T>::Getsize()
{
	return size;
}

template <class T>
TStack <T>::TStack (int n)
{
	if (n < 0) throw ("Negative size");
	if (n == 0)
	{
		size = 0;
		top = 0;
		mas = NULL;
	}
	else
	{
		size = n;
		top = 0;
		for (int i = 0; i < size; i++)
			mas[i] = 0;
	}
}

template <class T>
TStack <T>::TStack(TStack<T> &S)
{
	size = S.size;
	top = S.top;
	if (size == 0)
		mas = NULL;
	else
	{
		mas = new T[size];
		for (int i; i < size; i++)
			mas[i] = S.mas[i];
	}
}

template <class T>
bool TStack<T>::IsFull()
{
	if (top >= size)
		return 1;
	else
		return 0;
}

template <class T>
bool TStack<T>::IsEmpty()
{
	if (top == 0)
		return 1;
	else return 0;
}

template <class T>
T TStack<T>::Get()
{
	if (IsEmpty())
		throw TException("Stack is empty");
	top--;
	return mas[top];
}

template <class T>
T TStack<T>::Top()
{
	if (IsEmpty())
		throw ("Stack is empty");
	else
		return mas[top - 1];
}

template <class T>
TStack <T>::~TStack()
{
	top = 0;
	size = 0;
	delete[] mas;
}

template <class T>
void TStack<T>::Put(T A)
{
	if (IsFull())
		throw TException("Stack is full");
	else
	{
		mas[top] = A;
		top++;
	}
}

template <class T>
void TStack<T>::PrintStack()
{
	for (int i = top - 1; i >= 0; i--)
		cout << " " << mas[i];
}

template <class T>
int TStack<T>::operator!=(const TStack<T>&S) const
{
	return!(*this == S);
}

template <class T>
int TStack<T>::operator==(const TStack<T>&S) const
{
	if (top != S.top)
		return 0;
	if (size != size)
		return 0;
	for (int i = 0; i < top; i++)
	{
		if (mas[i] != S.mas[i])
			return 0;
	}
	return 1;
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>&S)
{
	if (this != &S)
	{
		delete[] mas;
		top = S.top;
		size = S.size;
		mas = new T[size];
		for (int i = 0; i < size; i++)
			mas[i] = S.mas[i];
	}
	return *this;
}
#pragma once
#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>

class Queue : public TStack <T> {
protected:
	int start; //начало очереди
	int num; //кол-возанятых ячеект
public:
	Queue(int n); //конструктор
	Queue(Queue <T> &q); //конструктор копирования
	virtual ~Queue(); //деструктор
	T Top();
	void Put(T a); //положить элемент
	T Get(); //взятие элемента
	bool IsFull(); //Полна ли очередь?
	bool IsEmpty();  //Пустая?
	void PrintQueue(); //Вывод
};

template <class T>
Queue<T>::Queue(int n) : TStack<T>(n)
{
	n=0;
	start = 0;
	num = 0;
}

template <class T>
Queue<T>::Queue(Queue<T> &q) : TStack<T>(q)
{
	start = q.start;
	num = q.num;
}

template <class T>
Queue<T>::~Queue()
{ }

template<class T>
inline T Queue<T>::Top() //встроенная функция
{
	return TStack<T>::mas[start];
}

template <class T>
void Queue<T>::Put(T a)
{
	if (IsFull())
		throw TException("Queue is full!");
	else
	{
		TStack<T>::Put(a);
		TStack<T>::top = TStack<T>::top % TStack<T>::size;
		num++;
	}
}


template <class T>
T Queue<T>::Get()
{
	if (IsEmpty())
		throw TException("Queue ie empty!");
	else
	{
		T temp = TStack<T>::mas[start];
		start = (start + 1) % TStack<T>::size;
		num--;
		return temp;
	}
}

template <class T>
bool Queue<T>::IsFull()
{
	if (num == TStack<T>::size)
		return 1;
	return 0;
}

template <class T>
bool Queue<T>::IsEmpty()
{
	if (num == 0)
		return 1;
	return 0;
}

template<class T>
void Queue<T>::PrintQueue()
{
	for (int i = start; i < TStack<T>::top; i = (i + 1) % TStack<T>::size) 
		cout << TStack<T>::mas[i];
}


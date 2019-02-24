#pragma once
#include <iostream>
#include "Exception.h"
#include "..//QueueLib/Queue.h"

using namespace std;

template <class T> 

class TArrayList 
{
protected:
	T * mas;                    //Массив элементов списка
	int *nextInd;              //Массив индексов, указывающих на следущий элемент списка
	int *predInd;              //Массив индексов, указывающих на предыдущий элемент списка
	int size;                  //Размер списка
	int num;                 //Количество элементов в списке
	int start;                 //Индекс первого элемента списка
	int end;                   //Индекс последнего элемента списка
	Queue <int> freeElem;     //Очередь пустых ячеек в массиве, 
public:
	TArrayList(int _size);  //Конструктор с параметром
	TArrayList(TArrayList<T> &A);  //Конструктор копирования
	~TArrayList();               //Деструктор
	void Put(int n, T elem);   //Добавить промежуточный элемент
	T Get(int n);              //Извлечь промежутьчный элемент 
	void PutStart(T elem);     //Положить в начало списка
	void PutEnd(T elem);       //Положить в конец списка 
	T GetStart();              //Забрать из начала списка с удалением
	T GetEnd();                //Забрать из конца списка с удалением
	bool IsFull();             //Проверка на полноту
	bool IsEmpty();            //Проверка на пустоту
	void Print();		//Вывод списка
	};

template <class T>
TArrayList<T>::TArrayList(int _size) : freeElem(_size)
{

	if (_size <= 0)
		throw TException("Uncurrent list's size");
	size = _size;
	num = 0;
	start = -1;
	end = -1;
	mas = new T[size];
	nextInd = new int[size];
	predInd = new int[size];
	for (int i = 0; i < size; i++)
	{
		nextInd[i] = -2;
		predInd[i] = -2;
		freeElem.Put(i);
	}
}

template <class T>
TArrayList<T>::TArrayList(TArrayList<T> &A) : freeElem(A.size)
{
	start = A.start;
	end = A.end;
	size = A.size;
	num = A.num;
	mas = new T[size];
	nextInd = new int[size];
	predInd = new int[size];
	
	freeElem = A.freeElem;
	for (int i = 0; i < size; i++)
	{
		mas[i] = A.mas[i];
		nextInd[i] = A.nextInd[i];
		predInd[i] = A.predInd[i];
	}
}

template<class T>
inline TArrayList<T>::~TArrayList()
{
	delete[] mas;
	delete[] nextInd;
	delete[] predInd;
}

template<class T>
void TArrayList<T>::Put(int n, T elem)
{
	if (IsFull())
		throw TException("List is full");
	if (n < 1 || n > num - 1)
		throw TException("Uncurrent index");
	int ifree = freeElem.Get();
	mas[ifree] = elem;
	int one = start;
	int two = nextInd[start];
	for (int i = 0; i < n - 1; i++)
	{
		one = two;
		two = nextInd[two];
	}
	nextInd[ifree] = two;
	nextInd[one] = ifree;

	predInd[ifree] = one;
	predInd[two] = ifree;
	num++;
}

template<class T>
T TArrayList<T>::Get(int n)
{
	if (IsEmpty())
		throw TException("List is empty");
	if (n < 1 || n > num - 1)
		throw TException("Uncurrent index");
	int ind = start;
	for (int i = 0; i < n; i++)
		ind = nextInd[ind];
	nextInd[predInd[ind]] = nextInd[ind];
	predInd[nextInd[ind]] = predInd[ind];
	T temp = mas[ind];
	freeElem.Put(ind);
	num--;
	return temp;
}

template <class T>
void TArrayList<T>::PutStart(T elem)
{
	if (IsFull())
		throw TException("List is full");
	int ifree = freeElem.Get();
	mas[ifree] = elem;
	nextInd[ifree] = start;
	if (start != -1)
		predInd[start] = ifree;
	else
		end = ifree;
	start = ifree;
	num++;
}

template <class T>
void TArrayList<T>::PutEnd(T elem)
{
	if (IsFull())
		throw TException("List is full");
	int ifree = freeElem.Get();
	mas[ifree] = elem;
	if (end != -1)
		nextInd[end] = ifree;
	else
	{
		start = ifree;
		predInd[ifree] = -1;
	}
	predInd[ifree] = end;
	end = ifree;
	num++;
}

template <class T>
T TArrayList<T>::GetStart()
{
	if (IsEmpty())
		throw TException("List is empty");
	T elem = mas[start];
	freeElem.Put(start);
	int newstart = nextInd[start];
	nextInd[start] = predInd[start] = -2;
	if (newstart != -1)
		predInd[newstart] = -1;
	num--;
	start = newstart;
	return elem;
}

template <class T>
T TArrayList<T>::GetEnd()
{
	if (IsEmpty())
		throw TException("List is empty");
	T elem = mas[end];
	int newFinish = predInd[end];
	predInd[end] = nextInd[end] = -2;
	freeElem.Put(end);
	end = newFinish;
	if (newFinish != -1)
		nextInd[newFinish] = -1;
	else
		start = -1;
	num--;
	return elem;
}

template <class T>
bool TArrayList<T>::IsFull()
{
	if (num == size)
		return true;
	return false;
}

template <class T>
bool TArrayList<T>::IsEmpty()
{
	if (num == 0)
		return true;
	return false;
}

template<class T>
inline void TArrayList<T>::Print()
{
	int it = start;
	for (int i = 0; i < num; i++)
	{
		cout << mas[it] << " ";
		it = nextInd[it];
	}
}
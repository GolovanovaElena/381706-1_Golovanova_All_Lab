#pragma once
#include "NewStack.h"
#include "Exception.h"

template <class T>
class TMltStack
{
protected:
	int size;
	T* mas;
	int n;
	TNewStack<T>** stackMas;
	int NumFree();
	void Repack(int _n);

public:
	TMltStack(int _n = 1, int _size = 10);
	TMltStack(TMltStack &A);
	int GetSize();
	void Set(int _n, T _elem);
	T Get(int _n);
	bool IsFull(int _n);
	bool IsEmpty(int _n);
	void PrintMltStack();
};

template <class T>
TMltStack<T>::TMltStack(int _n, int _size)
{
	if (_n <= 0 || _size <= 0)
		throw TException("Values ​​are not correct");
	n = _n;
	size = _size;

	stackMas = new TNewStack<T>*[n];
	mas = new T[size];

	int* p = new int[n];
	for (int i = 0; i < n; i++)
		p[i] = size / n;
	p[0] += size % n;

	T** q = new T*[n];
	q[0] = mas;
	for (int i = 1; i < n; i++)
		q[i] = q[i - 1] + p[i - 1];

	for (int i = 0; i < n; i++)
		stackMas[i] = new TNewStack<T>(p[i], q[i]);
}

template <class T>
TMltStack<T>::TMltStack(TMltStack &A)
{
	size = A.size;
	n = A.n;
	if (size == 0)
	{
		mas = NULL;
		stackMas = NULL;
	}
	else
	{
		mas = new T[size];
		for (int i = 0; i < n; i++)
			mas[i] = A.mas[i];

		stackMas = new TNewStack<T>*[n];

		int* p = new int[n];
		for (int i = 0; i < n; i++)
			p[i] = A.stackMas[i]->GetSize();

		T** q = new T*[n];
		q[0] = mas;
		for (int i = 1; i < n; i++)
			q[i] = p[i - 1] + q[i - 1];

		for (int i = 0; i < n; i++)
		{
			stackMas[i] = new TNewStack<T>(*A.stackMas[i]);
			stackMas[i]->SetMas(p[i], q[i]);
		}
	}
}

template <class T>
int TMltStack<T>::GetSize()
{
	return size;
}

template<class T>
void TMltStack<T>::Set(int _n, T _elem)
{
	if (_n < 0 || _n >= n)
		throw TException("Value ​​is not correct");
	else if (this->NumFree() == 0)
		throw TException("MultiStack is full");
	else if (IsFull(_n))
		Repack(_n);
	stackMas[_n]->Push(_elem);
}

template<class T>
T TMltStack<T>::Get(int _n)
{
	if (_n < 0 || _n >= n)
		throw TException("Value ​​is not correct");
	if (IsEmpty(_n))
		throw TException("MultiStack is full");
	return stackMas[_n]->Get();
}

template<class T>
bool TMltStack<T>::IsFull(int _n)
{
	if (_n < 0 || _n >= n)
		throw TException("Value ​​is not correct");
	return (stackMas[_n]->GetFreeMem() == 0);
}

template<class T>
bool TMltStack<T>::IsEmpty(int _n)
{
	if (_n < 0 || _n >= n)
		throw TException("Value ​​is not correct");
	return (stackMas[_n]->GetFreeMem() == stackMas[_n]->GetSize());
}

template <class T>
int TMltStack<T>::NumFree()
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		num += stackMas[i]->GetFreeMem();
	}
	return num;
}

template <class T>
void TMltStack<T>::Repack(int _n)
{
	int free = NumFree();
	int add_ev = free / n;
	int add_full = free % n;
	int* new_size = new int[n];
	T** new_start = new T*[n];
	T** old_start = new T*[n];

	for (int i = 0; i < n; i++)
		new_size[i] = add_ev + stackMas[i]->GetTop();
	new_size[_n] += add_full;

	new_start[0] = old_start[0] = mas;
	for (int i = 1; i < n; i++)
	{
		new_start[i] = new_start[i - 1] + new_size[i - 1];
		old_start[i] = old_start[i - 1] + stackMas[i - 1]->GetSize();
	}

	for (int i = 0; i < n; i++)
	{
		if (new_start[i] <= old_start[i])
			for (int j = 0; j < stackMas[i]->GetTop(); j++)
				new_start[i][j] = old_start[i][j];
		else
		{
			int s;
			for (s = i + 1; s < n; s++)
				if (new_start[s] <= old_start[s])
					break;
			for (int j = n - 1; j >= i; j--)
				for (int r = stackMas[j]->GetTop() - 1; r >= 0; r--)
					new_start[j][r] = old_start[j][r];
			i = s - 1;
		}
	}
	for (int i = 0; i < n; i++)
		stackMas[i]->SetMas(new_size[i], new_start[i]);
	delete[] new_size;
	delete[] new_start;
	delete[] old_start;
} 

template<class T>
void TMltStack<T>::PrintMltStack()
{
	int m = 0;
	cout << "\n\nMultiStack:";
	for (int i = 0; i < n; i++)
	{
		cout << endl << "Stack number " << i + 1 << "\n";
		stackMas[i]->PrintNewStack();
	}
}


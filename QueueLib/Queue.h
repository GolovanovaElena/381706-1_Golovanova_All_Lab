#pragma once
#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>

class Queue: public TStack<T> {
protected:
	int start; //������ �������
	int num; // ���-��������� �����
public:
	Queue(int n); //�����������
	Queue(Queue <T> &q); //����������� �����������
	virtual ~Queue(); //����������
	T Top();
	void Put(T a); //�������� �������
	T Get(); //������ ��������
	bool IsFull(); //����� �� �������?
	bool IsEmpty(); //������?
	void PrintQueue(); //�����
};

 template <class T>
 Queue<T>::Queue(int n) : TStack<T>(n)
	 {
	 start = 0;
	 num = 0;
	 }

 template <class T>
 Queue<T>::Queue(Queue<T> &q) : TStack<T>(q) //������ �� &q
 {
	 start = q.start;
	 num = q.num;
 }

 template <class T>
 Queue<T>::~Queue() //������ �� ���������?
 {
	 start = 0;
	 num = 0;
 }
  
 template<class T>
 inline T Queue<T>::Top() //���������� �������
 {
	 return TStack<T>::mas[start];
 }

 template <class T>
 void Queue<T>::Put(T a) //!!!!!!!!
 {
	 if (IsFull())
		 throw (TException("Queue is full!"));
	 else
	 {
		 TStack<T>::Put(a);
		 TStack<T>::top = TStack<T>::top % TStack<T>::size;
		 num++;
	 }
	}

 template <class T>
 T Queue<T>::Get()//!!!!!!!!
 {
	 if (IsEmpty())
		 throw TException("Queue is empty!");
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

 template <class T>
 void Queue<T>::PrintQueue()
 {
	 for (int i = start; i < TStack<T>::top; i = (i + 1) % TStack<T>::size)
		 cout << TStack<T>::mas[i];
 }
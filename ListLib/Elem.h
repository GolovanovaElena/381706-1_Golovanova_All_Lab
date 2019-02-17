#pragma once
#include <iostream> 

using namespace std;

template <class T>
class TElem
{
protected:
	T dannyye; // переменная под хранение данных
	TElem<T>* next; //указатель на следующий узел
public:
	TElem<T>(T _dannyye = 0, TElem<T>* n = 0); // конструктор по умолчанию
	TElem<T>(TElem<T>& A); //конструктор копирования
	T GetDannyye(); //получить значение из узла
	TElem<T>* GetNext(); //получить указатель на следующий узел
	void SetDannyye(T _dannyye);
	void SetNext(TElem<T>* n); //установить указатель на следующее звено списка
};

template <class T>
TElem<T>::TElem(T _dannyye, TElem<T>* n)
{
	dannyye = _dannyye;
	next = n;
}

template <class T>
TElem<T>::TElem(TElem<T>& A)
{
	dannyye = A.dannyye;
	next = A.next;
}

template <class T>
T TElem<T>::GetDannyye()
{
	return dannyye;
}

template <class T>
TElem<T>* TElem<T>::GetNext()
{
	return next;
}

template <class T>
void TElem<T>::SetDannyye(T _dannyye)
{
	dannyye = _dannyye;
}

template <class T>
void TElem<T>::SetNext(TElem<T>* n)
{
	next = n;
}
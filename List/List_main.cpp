#pragma once
#include "List.h"
//#include "Exception.h"

int main()
{
	try
	{
		TList<int> list;
		int one;
		int last;
		cout << "\nEnter the number of elements at the beginning at the List: ";
		cin >> one;
		for (int i = 1; i <= one; i++)
			list.PutBegin(i);
		cout << "\nEnter the number of elements at the last at the List: ";
		cin >> last;
		for (int i = 1; i <= last; i++)
			list.PutEnd(i);

		cout << "\n\nThe List:\n";
		list.Print();

		cout << "\n\nElement at the top of the List: " << list.GetBegin();
		cout << "\nElement at the end of the List: " << list.GetEnd();

		cout << "\n\nThe List is currently:\n";
		list.Print();
	}

	catch (TException exp)
	{
		exp.Print();
	}

	return 0;
}

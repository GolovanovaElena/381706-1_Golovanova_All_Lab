#include <iostream>
#include "..//ArrayListLib/ArrayList.h"

using namespace std;


int main()
{
	cout << "Example" << endl;
	cout << "Enter list's size: ";
	int n;
	cin >> n;
	cout << endl;
	try
	{
		TArrayList<int> aList(n);
		int i;
		for (i = 1; i <= n / 2; i++)
		{
			cout << "Put start: " << i << endl;
			aList.PutStart(i);
		}
		for (i; i <= n; i++)
		{
			cout << "Put end: " << i << endl;
			aList.PutEnd(i);
		}

		cout << "\n\nList create" << endl;
		aList.Print();
		cout << "\n\n";


		for (i = 1; i <= n / 2; i++)
			cout << "Get start: " << aList.GetStart() << endl;
		for (i; i <= n; i++)
			cout << "Get end: " << aList.GetEnd() << endl;
	}

	catch (TException exp)
	{
		exp.Print();
	}

	return 0;
}

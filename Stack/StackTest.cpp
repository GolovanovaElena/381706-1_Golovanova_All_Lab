#include <iostream>
#include "..//StackLib/Stack.h"

using namespace std;

int main()
{
	int n;
	cout << "Enter stac's size = ";
	cin >> n;
	try
	{
		TStack <int> stack(n);
		for (int i = 0; i < n; i++)
			stack.Put(i);
		cout << "\nStack:\n";
		stack.PrintStack();

		TStack <int> copyStack(n);
		cout << "\nCopyStack:\n";
		copyStack.PrintStack();
		 
		if (copyStack == stack)
			cout << "\nCopyStack=Stack";

		cout << "\nGet element of the Stack: " << stack.Get();

		cout << "\nStack now:\n";
		stack.PrintStack();

		if (copyStack != stack)
			cout << "\nCopyStack and Stack different\n";
	}

	catch (TException x)
	{
		x.Print();
	}
	return 0;
}

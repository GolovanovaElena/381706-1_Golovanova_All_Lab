#include "../MultiStackLib/MultiStack.h"
#include <ctime>
using namespace std;

int main()
{
	cout << "\tCreating multistack:" << endl;
	int m = 1;
	try
	{
		TMltStack<int> ms(5, 10);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 5; j++)
			{
				ms.Set(i, m);
				cout << " <" << m++ << "> is set to " << i + 1 << " stack" << endl;
			}

		ms.PrintMltStack();
		cout << "\n\n";

		for (int i = 0; i < 1; i++)
			cout << "Get element " << ms.Get(i) << " from " << i + 1 << " stack" << endl;

		ms.PrintMltStack();

		cout << "\n\nTry to repack and set '10' to 1 stack" << endl;
		ms.Set(1, 10);

		ms.PrintMltStack();
	}

	catch (TException exp)
	{
		exp.Print();
	}

	return 0;
}
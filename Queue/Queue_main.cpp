#include "Queue.h"
#include "Exception.h"
int main()
{
	cout << "Example program:" << endl;
	int n;
	cout << "Queue's size=" << endl;
	cin >> n;
	try
	{
		Queue<int> q(n);
		for (int i = 0; i < n; i++)
		{
			q.Put(i);
			cout << "Put " << i << endl;
		}

		while (!q.IsEmpty())
		{
			n = q.Get();
			cout << "Get " << n << endl;
		}
	}
	catch (TException exp)
	{
		exp.Print();
	}
	return 0;
}

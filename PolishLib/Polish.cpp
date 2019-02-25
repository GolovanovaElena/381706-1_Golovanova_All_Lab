#include "Polish.h"
#include <cstdlib>


int GetPriority(const char prior)
{
  switch (prior)
  {
  case '(':
    return 1;
  case ')':
    return 1;
  case '+':
    return 2;
  case '-':
    return 2;
  case '*':
    return 3;
  case '/':
    return 3;
  default:
    throw TException("It is not operator");
  }
}


Queue<char> ConvertToPol(TString str)
{
	int beg = 0;
	int end = 0;

	Queue<char> q(str.GetLength() * 3);
	TStack<char> st(str.GetLength() * 3);

	for (int i = 0; i < str.GetLength(); i++)
	{
		if (i == 0)
		{
			if (str[0] == '-')
			{
				q.Put('[');
				q.Put('0');
				q.Put(']');
			}
			else if (IsPolish(str[0]))
				if (GetPriority(str[0]) != 1)
					throw TException("Error math expression");
		}
		if (isdigit(str[i]))
		{
			q.Put('[');
			while ((i < str.GetLength()) && isdigit(str[i + 1]))
			{
				q.Put(str[i]);
				i++;
			}
			q.Put(str[i]);
			q.Put(']');
		}
		else if (st.IsEmpty() && IsPolish(str[i]))
		{
			st.Put(str[i]);
			if (str[i] == '(')
				beg++;
			if (str[i] == ')')
				throw TException("Error math expression");
		}
		else if (IsPolish(str[i]))
		{
			if (str[i] == '(')
			{
				st.Put(str[i]);
				beg++;
			}
			else if (str[i] == ')')
			{
				end++;
				while (st.Top() != '(')
					q.Put(st.Get());
				st.Get();
			}
			else
			{
				int p = GetPriority(str[i]);
				if (p > GetPriority(st.Top()))
					st.Put(str[i]);
				else if (p <= GetPriority(st.Top()))
				{
					while (!st.IsEmpty() && p <= GetPriority(st.Top()))
						q.Put(st.Get());
					st.Put(str[i]);
				}
			}
		}
		else if (str[i] != '\0')
			throw TException("Error math expression");
	}
	while (!st.IsEmpty())
		q.Put(st.Get());
	if (beg != end)
		throw TException("Error math expression");
	return q;
}


double Res(Queue<char> que)
{
	double res = 0;
	TStack<double> st(que.Getsize());
	if (IsPolish(que.Top()))
		throw TException("Error in queue");
	int i = 0;
	int dit = 0;
	int tmp = 0;
	while (!que.IsEmpty())
	{
		i++;
		char c = que.Get();
		if (c == '[')
		{
			dit++;
			c = que.Get();
			double tmp = std::atof(&c);
			while (que.Top() != ']' && !que.IsEmpty())
			{
				c = que.Get();
				tmp = tmp * 10 + std::atof(&c);
			}
			que.Get();
			st.Put(tmp);
		}
		else if (IsPolish(c))
		{
			double A = st.Get();
			double B = st.Get();
			double C = 0;
			if (c == '+')
				C = B + A;
			if (c == '-')
				C = B - A;
			if (c == '*')
				C = B * A;
			if (c == '/')
				C = B / A;
			st.Put(C);
		}
		else
			throw TException("Error symbol queue");
		if (i == 2 && dit != 2)
			throw TException("Error in queue");
	}
	res = st.Get();
	if (!st.IsEmpty())
		throw TException("Error in queue");
	return res;
}

bool IsPolish(char s)
{
	return (s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == ')');
}
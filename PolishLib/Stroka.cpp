#include "Stroka.h"
#include <string.h>


TString::TString()
{
	string = 0;
	length = 0;
}


TString::TString(TString &str)
{
	length = str.length;
	if (length != 0)
	{
		string = new char[length];
		for (int i = 0; i < length; i++)
			string[i] = str.string[i];
	}
	else
		string = 0;
}


TString::TString(char* _string) 
{
  if (_string == 0)
    throw TException("String is empty");

  if (_string[0] == '\0')
    return;

  length = strlen(_string) + 1; 
  string = new char[length];
  for (int i = 0; i < length - 1; i++)
    string[i] = _string[i];
  string[length - 1] = 0;
}


TString::~TString()
{
	if (string != 0)
		delete [] string;
}


int TString::GetLength()
{
	return length;
}


void TString::DeleteString()
{
	*string = '\0';
	length = 0;
}


TString TString::operator+(TString &str)
{
	TString temp;
	temp.length = length + str.length - 1;
	temp.string = new char[temp.length];
	for (int i = 0; i < length - 1; i++)
	{
		temp.string[i] = string[i];
	}
	for (int i = length - 1; i < temp.length; i++)
	{
		temp.string[i] = str.string[i - (length - 1)];
	}
	return temp;
}

TString& TString::operator=(TString &str)
{
	if (this != &str)
	{
		length = str.length;
		if (length != 0)
		{
			if (string != 0)
				delete[]string;
			string = new char[str.length];
			for (int i = 0; i < str.length; i++)
			{
				string[i] = str.string[i];
			}
		}
		else
		{
			if (string != 0)
				delete[]string;
			string = 0;
		}
	}
	return *this;
}


char& TString::operator[](int i)
{
  if ((i >= 0) && (i < length))
    return string[i];
  throw TException("Index is uncurrent");
}


std::istream& operator>>(std::istream &istr, TString &str)
{
	char s[256] = {0};
	istr >> s;

	str.length = strlen(s) + 1;
	str.string = new char[str.length];
	for (int i = 0; i < str.length - 1; i++)
	{
		str.string[i] = s[i];
	}
	str.string[str.length - 1] = 0;
	return istr;
}


std::ostream& operator<<(std::ostream &ostr, const TString &str)
{
	ostr << str.string;
	return ostr;
}
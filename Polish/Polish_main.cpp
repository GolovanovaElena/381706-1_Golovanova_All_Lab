#include "Polish.h"
//#include <conio.h>
#include <stdlib.h>

int  main()
{


	try
	{
		cout << "Enter your math expression: ";
		TString s;
		cin >> s;
		cout << s << " ~ ";
		Queue<char> B;
		B = ConvertToPol(s);
		B.PrintQueue();
		cout << " = " << Res(B) << endl;
	}
  
  catch (TException exp)
  {
    exp.Print();
  }
	//getch();
  return 0;
}

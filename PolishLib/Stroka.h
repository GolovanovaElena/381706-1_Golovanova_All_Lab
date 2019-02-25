#pragma once
#include <iostream>
#include "Exception.h"

class TString
{
protected:
  char* string;																						
  int length;																							

public:
  TString();
  TString(TString &str);
  TString(char* _string);
  ~TString();

  int GetLength();																				
  void DeleteString();																	

  TString operator+(TString &str);
  TString& operator=(TString &str);
  char& operator[](int i);

  friend std::istream& operator>>(std::istream &istr, TString &str);
  friend std::ostream& operator<<(std::ostream &ostr, const TString &str);
};
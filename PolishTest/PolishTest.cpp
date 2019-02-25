#include "gtest.h"
#include "Polish.h"

TEST(Polish, can_get_priority)
{
  ASSERT_EQ(1, GetPriority(')'));
  ASSERT_EQ(1, GetPriority('('));
  ASSERT_EQ(2, GetPriority('+'));
  ASSERT_EQ(2, GetPriority('-'));
  ASSERT_EQ(3, GetPriority('*'));
  ASSERT_EQ(3, GetPriority('/'));
  ASSERT_ANY_THROW(GetPriority('!'));
}

/*TEST(Polish, can_convert_to_pol)
{
  char s[] = "3+2";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);
  ASSERT_EQ(q.Get(), '[');
  ASSERT_EQ(q.Get(), '3');
  ASSERT_EQ(q.Get(), ']');
  ASSERT_EQ(q.Get(), '[');
  ASSERT_EQ(q.Get(), '2');
  ASSERT_EQ(q.Get(), ']');
  ASSERT_EQ(q.Get(), '+');
} */

TEST(Polish, can_add)
{
  char s[] = "3+7";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);
  EXPECT_EQ(10, Res(q));
}

TEST(Polish, can_add_two_big_number) 
{
  char s[] = "5+13";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);
  EXPECT_EQ(18, Res(q));
}

TEST(Polish, can_subtract) 
{
  char s[] = "54-1";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);
  EXPECT_EQ(53, Res(q));
}

TEST(Polish, can_mult)
{
  char s[] = "4*6";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);
  EXPECT_EQ(24, Res(q));
}

TEST(Polish, can_mult_with_three_parametr) 
{
  char s[] = "4*1*3";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);
  EXPECT_EQ(12, Res(q));
}

TEST(Polish, can_mult_and_add_whith_hooks) 
{
  char s[] = "(2+8)*3";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);
  EXPECT_EQ(30, Res(q));
}

TEST(Polish, can_mult_and_add_whithout_hooks) 
{
  char s[] = "9+3*3";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);
  EXPECT_EQ(18, Res(q));
}

TEST(Polish, can_split)
{
  char s[] = "160/4";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);
  EXPECT_EQ(40, Res(q));
}

TEST(Polish, can_mult_large_with_hooks) 
{
  char s[] = "(5+3)*12";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);
  EXPECT_EQ(96, Res(q));
}

TEST(Polish, can_mult_and_split_with_hooks)
{
  char s[] = "(5+3)/4";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);
  EXPECT_EQ(2, Res(q));
}

TEST(Polish, can_add_and_split_with_hooks) 
{
  char s[] = "(5+3)/(8-4)";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);

  EXPECT_EQ(2, Res(q));
}

TEST(Polish, can_add_and_split_with_negative_first_number) 
{
  char s[] = "-6+(5+3)/(10-6)";
  TString str(s);
  Queue<char> q;
  q = ConvertToPol(str);

  EXPECT_EQ(-4, Res(q));
}

TEST(Polish, can_check_ispolish)
{
	ASSERT_EQ(1, IsPolish(')'));
	ASSERT_EQ(1, IsPolish('('));
	ASSERT_EQ(1, IsPolish('+'));
	ASSERT_EQ(1, IsPolish('-'));
	ASSERT_EQ(1, IsPolish('*'));
	ASSERT_EQ(1, IsPolish('/'));
	ASSERT_EQ(false, IsPolish('25'));
	ASSERT_EQ(false, IsPolish('!'));
}

TEST(Polish, throw_when_math_expression_have_wrong_symbol)
{
	char s[] = "1!5";
	TString str(s);
	ASSERT_ANY_THROW(ConvertToPol(str));
}


TEST(Polish, throw_when_math_expression_have_wrong_hooks)
{
	char s[] = "(2*8";
	TString str(s);
	ASSERT_ANY_THROW(ConvertToPol(str));
}

TEST(Polish, throw_when_math_expression_have_wrong_begin)
{
	char s[] = "/5*5";
	TString str(s);
	ASSERT_ANY_THROW(ConvertToPol(str));
}

TEST(Polish, no_throw_when_queue_is_rigth)
{
	Queue<char> q(7);
	q.Put('[');
	q.Put('2');
	q.Put(']');
	q.Put('[');
	q.Put('2');
	q.Put(']');
	q.Put('*');
	ASSERT_NO_THROW(Res(q));
	ASSERT_EQ(Res(q), 4);
}

TEST(Polish, throw_when_queue_have_wrong_begin)
{
	Queue<char> q(7);
	q.Put('/');
	q.Put('[');
	q.Put('4');
	q.Put(']');
	q.Put('[');
	q.Put('4');
	q.Put(']');
	ASSERT_ANY_THROW(Res(q));
}

TEST(Polish, throw_when_queue_is_wrong)
{
	Queue<char> q(7);
	q.Put('[');
	q.Put('3');
	q.Put(']');
	q.Put('+');
	q.Put('[');
	q.Put('7');
	q.Put(']');
	ASSERT_ANY_THROW(Res(q));
}

TEST(Polish, throw_when_queue_absolutely_wrong)
{
	Queue<char> q(10);
	q.Put('[');
	q.Put('7');
	q.Put(']');
	q.Put('[');
	q.Put('5');
	q.Put(']');
	q.Put('*');
	q.Put('[');
	q.Put('6');
	q.Put(']');
	ASSERT_ANY_THROW(Res(q));
}

TEST(Polish, throw_when_queue_have_wrong_symbol)
{
	Queue<char> q(7);
	q.Put('[');
	q.Put('7');
	q.Put(']');

	q.Put('[');
	q.Put('5');
	q.Put(']');
	q.Put(',');
	ASSERT_ANY_THROW(Res(q));
}

#include "TabLib.h"

#include <gtest.h>

TEST(TabLib, can_create_tab_with_positive_size)
{
  ASSERT_NO_THROW(TTab<int> s(1));
}


TEST(TabLib, throws_when_create_tab_with_negative_size)
{
  ASSERT_ANY_THROW(TTab<int> s(-8));
}



TEST(TabLib, can_copy_tab)
{
  TTab<int> A;
  ASSERT_NO_THROW(TTab<int> s(A));
}

TEST(TabLib, can_put_to_tab)
{
  TTab<int> A(4);
  ASSERT_NO_THROW(A.Put("kig", 7));
}

TEST(TabLib, throws_when_put_to_full_tab)
{
  TTab<int> A(1);
  A.Put("iun", 5);
  ASSERT_ANY_THROW(A.Put("dhj", 7));
}

TEST(TabLib, can_get_from_tab)
{
  TTab<int> A(4);
  A.Put("kif", 98);
  int k;
  ASSERT_NO_THROW(k = A["kif"]);
}

TEST(TabLib, can_delete_from_tab)
{
  TTab<int> s(1);
  s.Put("kig", 7);
  ASSERT_NO_THROW(s.Del("kig"));
}

TEST(TabLib, throws_when_delete_from_empty_Tab)
{
  TTab<int> A(1);
  ASSERT_ANY_THROW(A.Del("kj"));
}

TEST(TabLib, get_gives_right_answer)
{
  TTab<int> A(2);
  A.Put("bol", 8);
  int k = A["bol"];
  EXPECT_EQ(8, k);
}

TEST(TabLib, isfull_gives_right_true_answer)
{
  TTab<int> A(1);
  A.Put("kdgjh", 8);
  EXPECT_EQ(true, A.IsFull());
}

TEST(TabLib, isfull_gives_right_false_answer)
{
  TTab<int> A(1);
  EXPECT_EQ(false, A.IsFull());
}

TEST(TabLib, isempty_gives_right_true_answer)
{
  TTab<int> A(1);
  EXPECT_EQ(true, A.IsEmpty());
}

TEST(TabLib, isempty_gives_right_false_answer)
{
  TTab<int> A(1);
  A.Put("kdgjh", 8);
  EXPECT_EQ(false, A.IsEmpty());
}
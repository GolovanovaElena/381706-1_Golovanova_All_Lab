#include "..//StackLib/Stack.h"
#include <gtest.h>

TEST(Stack, throws_when_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack <int> S(-5));
}

TEST(Stack, can_put_and_get)
{
	TStack <int> S(2);
	S.Put(4);
	ASSERT_EQ(4, S.Get());
}

TEST(Stack, can_use_full_check_false)
{
	TStack <int> S(12);
	ASSERT_FALSE(S.IsFull());
}

TEST(Stack, can_use_full_check_true)
{
	TStack <int> S(3);
	S.Put(4);
	S.Put(4);
	S.Put(4);
	ASSERT_TRUE(S.IsFull());
}

TEST(Stack, can_use_empty_check_false)
{
	TStack <int> S(2);
	S.Put(4);
	ASSERT_FALSE(S.IsEmpty());
}

TEST(Stack, can_use_empty_check_true)
{
	TStack <int> S(8);
	ASSERT_TRUE(S.IsEmpty());
}

TEST(Stack, throws_when_in_full_stack_put_elem)
{
	TStack <int> S(3);
	S.Put(8);
	S.Put(8);
	S.Put(8);
	ASSERT_ANY_THROW(S.Put(9));
}

TEST(Stack, throws_when_from_empty_stack_get_elem)
{
	TStack <int> S(2);
	ASSERT_ANY_THROW(S.Get());
}

TEST(Stack, Comparison_true)
{
	TStack <int> S(2), S2(2);
	S.Put(2);
	S2.Put(2);
	ASSERT_TRUE(S == S2);
}

TEST(Stack, Comparison_false)
{
	TStack <int> S(1), S2(1);
	S.Put(1);
	S2.Put(2);
	ASSERT_FALSE(S == S2);
}

TEST(Stack, Comparison_false_when_dif_size)
{
	TStack <int> S(2), S2(3);
	ASSERT_FALSE(S == S2);
}

TEST(Stack, Comparison_false_when_dif_top)
{
	TStack <int> S(4), S2(4);
	S.Put(1);
	S2.Put(1), S2.Put(2);
	ASSERT_FALSE(S == S2);
}

TEST(Stack, NoComparison_false)
{
	TStack <int> S(1), S2(1);
	S.Put(1);
	S2.Put(1);
	ASSERT_FALSE(S != S2);
}

TEST(Stack, NoComparison_true)
{
	TStack <int> S(1), S2(1);
	S.Put(1);
	S2.Put(2);
	ASSERT_TRUE(S != S2);
}

TEST(Stack, NoComparison_true_when_dif_size)
{
	TStack <int> S(1), S2(3);
	ASSERT_TRUE(S != S2);
}

TEST(Stack, NoComparison_false_when_dif_top)
{
	TStack <int> S(3), S2(3);
	S.Put(1);
	S2.Put(1), S2.Put(2);
	ASSERT_TRUE(S != S2);
}

TEST(Stack, Assignment)
{
	TStack <int> S(3), S2(1);
	S.Put(1), S.Put(2), S.Put(3);
	S2 = S;
	ASSERT_TRUE(S2 == S);
}

TEST(Stack, Correct_order)
{
	TStack <int> S(3);
	S.Put(1), S.Put(2), S.Put(3);
	ASSERT_EQ(S.Get(), 3);
	ASSERT_EQ(S.Get(), 2);
	ASSERT_EQ(S.Get(), 1);
}
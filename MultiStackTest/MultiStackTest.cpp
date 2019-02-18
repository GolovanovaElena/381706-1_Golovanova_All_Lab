#include "gtest.h"
#include "../MultiStackLib/MultiStack.h"

TEST(TNewStack, throws_when_create_newstack_with_negative_size)
{
	int *a = NULL;
	ASSERT_ANY_THROW(TNewStack<int> S(-5, a));
}

TEST(TNewStack, can_create_newstack)
{
	int *a = NULL;
	ASSERT_NO_THROW(TNewStack<int> S(3, a));
}

TEST(TNewStack, can_create_copy_newstack)
{
	int *a = NULL;
	TNewStack<int> S(3, a);
	ASSERT_NO_THROW(TNewStack<int> Sn(S));
}

TEST(TNewStack, can_get_free_mem)
{
	int *a = new int[9];
	TNewStack<int> S(9, a);
	S.Push(5);
	S.Push(9);
	ASSERT_EQ(7, S.GetFreeMem());
}

TEST(TNewStack, can_get_top)
{
	int *a = new int[6];
	TNewStack<int> S(6, a);
	S.Put(8);
	S.Put(4);
	S.Put(5);
	S.Put(98);
	ASSERT_EQ(4, S.GetTop());
}

TEST(TNewStack, can_get_size)
{
	int *a = NULL;
	TNewStack<int> S(85, a);
	ASSERT_EQ(85, S.GetSize());
}

TEST(TNewStack, can_set_multistack)
{
	int *a = new int[7];
	int *b = new int[7];
	TNewStack<int> S(7, a);
	S.SetMas(14, b);
	ASSERT_EQ(14, S.GetSize());
}

TEST(TNewStack, throw_set_multistack_negative_size)
{
	int *a = new int[95];
	int *b = new int[95];
	TNewStack<int> S(95, a);
	ASSERT_ANY_THROW(S.SetMas(-5, b));
}

TEST(TNewStack, can_put_and_get_elem)
{
	int *a = new int[6];
	TNewStack<int> S(6, a);
	S.Push(9);
	S.Push(5);
	S.Push(1);
	ASSERT_EQ(1, S.Get());
	ASSERT_EQ(5, S.Get());
	ASSERT_EQ(9, S.Get());
}

TEST(TMltStack, can_create_multistack_with_positive_length)
{
	ASSERT_NO_THROW(TMltStack<int> A(4, 24));
}

TEST(TMltStack, cant_create_multistack_with_negative_length)
{
	ASSERT_ANY_THROW(TMltStack<int> A(2, -2));
}

TEST(TMltStack, cant_create_multistack_with_negative_kol)
{
	ASSERT_ANY_THROW(TMltStack<int> A(0, 20));
}

TEST(TMltStack, can_copy_multistack)
{
	TMltStack<int> A(9, 15);
	ASSERT_NO_THROW(TMltStack<int> B(A));
}

TEST(TMltStack, can_get_size)
{
	TMltStack<int> A(7, 77);
	ASSERT_EQ(A.GetSize(), 77);
}

TEST(TMltStack, can_set_element)
{
	TMltStack<int> A(5, 25);
	ASSERT_NO_THROW(A.Set(1, 2));
}

TEST(TMltStack, throws_when_set_element_in_full_multistack)
{
	TMltStack<int> A(2, 4);
	A.Set(0, 1);
	A.Set(0, 2);
	A.Set(1, 3);
	A.Set(1, 4);
	ASSERT_ANY_THROW(A.Set(1, 6));
}

TEST(TMltStack, throws_when_set_element_in_negative_index)
{
	TMltStack<int> A(7, 16);
	ASSERT_ANY_THROW(A.Set(-5, 1));
}

TEST(TMltStack, can_get_element)
{
	TMltStack<int> A(5, 25);
	A.Set(2, 43);
	ASSERT_EQ(43, A.Get(2));
}

TEST(TMltStack, can_repack)
{
	TMltStack<int> A(2, 6);
	A.Set(0, 1);
	A.Set(0, 2);
	A.Set(0, 3);
	A.Set(1, 3);
	ASSERT_NO_THROW(A.Set(0, 10));
	ASSERT_EQ(A.Get(0), 10);
}

TEST(TMltStack, throws_when_get_element_from_negative_index)
{
	TMltStack<int> A(5, 25);
	A.Set(1, 43);
	ASSERT_ANY_THROW(A.Get(-2));
}

TEST(TMltStack, throws_when_get_element_from_empty_multistack)
{
	TMltStack<int> A(3, 5);
	ASSERT_ANY_THROW(A.Get(2));
}

TEST(TMltStack, correct_order_return_value)
{
	TMltStack <int> A(2, 5);
	A.Set(1, 4);
	A.Set(1, 5);
	A.Set(1, 6);
	ASSERT_EQ(6, A.Get(1));
	ASSERT_EQ(5, A.Get(1));
	ASSERT_EQ(4, A.Get(1));
}

TEST(TMltStack, can_check_is_empty)
{
	TMltStack<int> A(9, 99);
	ASSERT_TRUE(A.IsEmpty(1));
}

TEST(TMltStack, can_check_is_no_empty)
{
	TMltStack<int> A(9, 99);
	A.Set(2, 2);
	ASSERT_FALSE(A.IsEmpty(2));
}

TEST(TMltStack, can_check_is_full)
{
	TMltStack<int> A(5, 25);
	A.Set(1, 43);
	A.Set(1, 43);
	A.Set(1, 43);
	A.Set(1, 43);
	A.Set(1, 43);
	EXPECT_EQ(1, A.IsFull(1));
}

TEST(TMltStack, can_check_is_no_full)
{
	TMltStack<int> A(9, 99);
	A.Set(1, 43);
	A.Set(1, 43);
	A.Set(1, 43);
	ASSERT_FALSE(A.IsFull(1));
}

TEST(TMltStack, throw_when_check_is_full_or_empty)
{
	TMltStack<int> A(5, 25);
	ASSERT_ANY_THROW(A.IsFull(-1));
	ASSERT_ANY_THROW(A.IsEmpty(-1));
}
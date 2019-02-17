#include "gtest.h"
#include "StackList.h"

TEST(TStackList, can_create_stack)
{
	ASSERT_NO_THROW(TStackList<int> A);
}

TEST(TStackList, can_create_create_with_parametr)
{
	ASSERT_NO_THROW(TStackList<int> A(5));
}

TEST(TStackList, can_create_create_with_negative_size)
{
	ASSERT_ANY_THROW(TStackList<int> A(-12));
}

TEST(TStackList, can_create_copy_create)
{
	TStackList<int> S(4);
	ASSERT_NO_THROW(TStackList<int> A(S));
}

TEST(TStackList, can_get_max_size)
{
	TStackList<int> S(1105);
	ASSERT_EQ(S.GetMaxSize(), 1105);
}

TEST(TStackList, can_get_size)
{
	TStackList<int> S(7);
	S.Put(1);
	ASSERT_EQ(S.GetSize(), 1);
}

TEST(TStackList, can_get)
{
	TStackList<int> A;
	A.Put(43);
	EXPECT_EQ(43, A.Get());
}

TEST(TStackList, can_put)
{
	TStackList<int> A;
	ASSERT_NO_THROW(A.PutBegin(4));
}

TEST(TStackList, throws_when_in_full_stack_put_elem)
{
	TStackList<int> S(4);
	S.Put(4);
	S.Put(4);
	S.Put(3);
	S.Put(3);
	ASSERT_ANY_THROW(S.Put(5));
}

TEST(TStackList, throws_when_from_empty_stack_get_elem)
{
	TStackList <int> S(8);
	ASSERT_ANY_THROW(S.Get());
}

TEST(TStackList, can_use_empty_check_true)
{
	TStackList<int> S(9);
	ASSERT_TRUE(S.IsEmpty());
}


TEST(TStackList, can_use_empty_check_false)
{
	TStackList<int> S(2);
	S.Put(2);
	S.Put(2);
	ASSERT_FALSE(S.IsEmpty());
}

TEST(TStackList, can_check_empty_print)
{
	TStackList<int> S(7);
	ASSERT_ANY_THROW(S.Print());
}

TEST(TStackList, correct_order)
{
	TStackList<int> S(3);
	S.Put(3), S.Put(5), S.Put(7);
	ASSERT_EQ(S.Get(), 7);
	ASSERT_EQ(S.Get(), 5);
	ASSERT_EQ(S.Get(), 3);
}


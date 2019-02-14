#include <gtest.h>
#include "Queue.h"

TEST(Queue, throws_when_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(Queue<int> S(-2));
}

TEST(Queue, chek_put_and_get)
{
	Queue <int> Q(1);
	Q.Put(4);
	ASSERT_EQ(4, Q.Get());
}

TEST(Queue, can_use_full_check_false)
{
	Queue <int> Q(1);
	ASSERT_FALSE(Q.IsFull());
}

TEST(Queue, can_use_full_check_true)
{
	Queue <int> Q(2);
	Q.Put(5);
	Q.Put(6);
	ASSERT_TRUE(Q.IsFull());
}

TEST(Queue, can_use_empty_check_false)
{
	Queue <int> Q(2);
	Q.Put(6);
	Q.Put(5);
	ASSERT_FALSE(Q.IsEmpty());
}

TEST(Queue, can_use_empty_check_true)
{
	Queue <int> Q(2);
	ASSERT_TRUE(Q.IsEmpty());
}

TEST(Queue, throw_get_when_is_empty)
{
	Queue <int> Q(1);
	ASSERT_ANY_THROW(Q.Get());
}

TEST(Queue, throw_put_when_is_full)
{
	Queue <int> Q(2);
	Q.Put(1);
	Q.Put(5);
	ASSERT_ANY_THROW(Q.Put(3));
}

TEST(Queue, check_circular_put)
{
	Queue <int> Q(4);
	for (int i = 0; i < 4; i++)
		Q.Put(i);  //1 2 3 4

	Q.Get(); //2 3 4
	Q.Get();// 3 4

	Q.Put(4); //3 4 4
	Q.Get(); //4 4
	ASSERT_EQ(4, Q.Get());
}


TEST(Queue, Correct_order)
{
	Queue<int> S(5);
	S.Put(1), S.Put(2), S.Put(3), S.Put(9), S.Put(8);
	ASSERT_EQ(S.Get(), 1);
	ASSERT_EQ(S.Get(), 2);
	ASSERT_EQ(S.Get(), 3);
	ASSERT_EQ(S.Get(), 9);
	ASSERT_EQ(S.Get(), 8);
}

#include "List.h"

#include <gtest.h>

TEST(List, can_create_List)
{
	ASSERT_NO_THROW(List<int>A);
}

TEST(List, can_create_List_with_positive_length)
{
	ASSERT_NO_THROW(List<int> v(3));
}

TEST(List, throws_when_create_List_with_negative_size)
{
	ASSERT_ANY_THROW(List<int> v(-5));
}

TEST(List, Can_copy_List)
{
	List<int>q(4);
	ASSERT_NO_THROW(List<int>w(q));
}
TEST(List, IsEmpty)
{
	List<int>q;
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(List, push_back)
{
	List<int>q;
	q.push_back(0);
	q.push_back(1);
	int r = q.pop_back();
	EXPECT_EQ(r, 1);
}

TEST(List, pop_front)
{
	List<int> v(5);
	int m = 3;
	v.push_front(0);
	v.push_front(1);
	v.push_front(2);
	v.pop_front();
	v.pop_front();
	int t = v.pop_front();
	EXPECT_EQ(t, 0);
}







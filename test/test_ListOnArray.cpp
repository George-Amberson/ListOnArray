#include "ListOnArray.h"

#include <gtest.h>

TEST(ListOnArray, can_create_ListOnArray)
{
	ASSERT_NO_THROW(ListOnArray<int>A);
}



TEST(ListOnArray, Can_copy_ListOnArray)
{
	ListOnArray<int>q;
	ASSERT_NO_THROW(ListOnArray<int>w(q));
}
TEST(ListOnArray, IsEmpty)
{
	ListOnArray<int>q;
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(ListOnArray, push_back)
{
	ListOnArray<int>q(2);
	q.push_back(0);
	q.push_back(1);
	int r = q.pop_back();
	EXPECT_EQ(r, 1);
}

TEST(ListOnArray, pop_front)
{
	ListOnArray<int> v(3);
	int m = 3;
	v.push_front(0);
	v.push_front(1);
	v.push_front(2);
	v.pop_front();
	v.pop_front();
	int t = v.pop_front();
	EXPECT_EQ(t, 0);
}









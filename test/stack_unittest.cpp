#include "gtest/gtest.h"
#include "stack.hpp"

TEST(StackTest, int) {
	Stack<int> s;
	s.push(10);
	ASSERT_EQ(10, s.top());
}

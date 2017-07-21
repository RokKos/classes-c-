#include <string>

#include "gtest/gtest.h"
#include "stack.hpp"

TEST(StackTest, int) {
	Stack<int> s;
	// Check if its initiali empty
	ASSERT_EQ(true, s.isEmpty());

	for (int i = 0; i < 10; ++i) {
		s.push(i+1);
	}

	ASSERT_EQ(10, s.size());
	ASSERT_EQ(10, s.top());
	ASSERT_EQ(10, s.pop());
	s.push(11);
	ASSERT_EQ(11, s.pop());

	for (int i = 9; i >=5 ; i--) {
		ASSERT_EQ(i, s.pop());
	}

	ASSERT_EQ(false, s.isEmpty());
	ASSERT_EQ(4, s.size());

	for (int i = 4; i >=1 ; i--) {
		ASSERT_EQ(i, s.pop());
	}

	ASSERT_EQ(true, s.isEmpty());
	ASSERT_EQ(0, s.size());
}


TEST(StackTest, string) {
	std::string arr[10] = {"aaa", "bbb", "ccc", "ddd", "eeeeee", "ff", "g",
	 						"iiii", "jjjjj", "kk"};

	Stack<std::string> s;

	// Check if its initiali empty
	ASSERT_EQ(true, s.isEmpty());

	for (int i = 0; i < 10; ++i) {
		s.push(arr[i]);
	}

	ASSERT_EQ(10, s.size());
	ASSERT_EQ(arr[9], s.top());
	ASSERT_EQ(arr[9], s.pop());
	s.push(arr[5]);
	ASSERT_EQ(arr[5], s.pop());

	for (int i = 8; i >=4 ; i--) {
		ASSERT_EQ(arr[i], s.pop());
	}

	ASSERT_EQ(false, s.isEmpty());
	ASSERT_EQ(4, s.size());

	for (int i = 3; i >=0 ; i--) {
		ASSERT_EQ(arr[i], s.pop());
	}

	ASSERT_EQ(true, s.isEmpty());
	ASSERT_EQ(0, s.size());
}

TEST(StackTest, Poping_empty_stack) {
	Stack<int> s;
	ASSERT_EQ(0, s.pop());
	for (int i = 0; i < 5; ++i) {
		s.push(i);
	}
	for (int i = 4; i >= 0; --i) {
		ASSERT_EQ(i, s.pop());
	}

	ASSERT_EQ(0, s.pop());
	ASSERT_EQ(0, s.pop());

	Stack<std::string> ss;

	ASSERT_EQ(true, ss.pop().empty());  // Check if string is empty
	std::string arr[5] = {"aaa", "bbb", "ccc", "ddd", "eeeeee"};

	for (int i = 0; i < 5; ++i) {
		ss.push(arr[i]);
	}

	for (int i = 4; i >=0 ; i--) {
		ASSERT_EQ(arr[i], ss.pop());
	}

	ASSERT_EQ(true, ss.pop().empty());
	ASSERT_EQ(true, ss.pop().empty());
}

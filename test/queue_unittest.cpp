#include <string>

#include "gtest/gtest.h"
#include "queue.hpp"

TEST(QueueTest, int) {
	Queue<int> s;
	// Check if its initiali empty
	ASSERT_EQ(true, s.isEmpty());

	for (int i = 0; i < 10; ++i) {
		s.push(i+1);
	}

	ASSERT_EQ(10, s.size());
	ASSERT_EQ(1, s.top());
	ASSERT_EQ(1, s.pop());
	s.push(11);
	ASSERT_EQ(2, s.pop());

	for (int i = 3; i <=7 ; ++i) {
		ASSERT_EQ(i, s.pop());
	}

	ASSERT_EQ(false, s.isEmpty());
	ASSERT_EQ(4, s.size());

	for (int i = 8; i <=11 ; ++i) {
		ASSERT_EQ(i, s.pop());
	}

	ASSERT_EQ(true, s.isEmpty());
	ASSERT_EQ(0, s.size());
}

TEST(QueueTest, string) {
	std::string arr[10] = {"aaa", "bbb", "ccc", "ddd", "eeeeee", "ff", "g",
	 						"iiii", "jjjjj", "kk"};

	Queue<std::string> s;

	// Check if its initiali empty
	ASSERT_EQ(true, s.isEmpty());

	for (int i = 0; i < 10; ++i) {
		s.push(arr[i]);
	}

	ASSERT_EQ(10, s.size());
	ASSERT_EQ(arr[0], s.top());
	ASSERT_EQ(arr[0], s.pop());
	s.push(arr[5]);
	ASSERT_EQ(arr[1], s.pop());

	for (int i = 2; i <=6; ++i) {
		ASSERT_EQ(arr[i], s.pop());
	}


	ASSERT_EQ(false, s.isEmpty());
	ASSERT_EQ(4, s.size());

	for (int i = 7; i <=9 ; ++i) {
		ASSERT_EQ(arr[i], s.pop());
	}

	ASSERT_EQ(arr[5], s.pop());
	ASSERT_EQ(true, s.isEmpty());
	ASSERT_EQ(0, s.size());
}

TEST(QueueTest, Poping_empty_Queue) {
	Queue<int> s;
	ASSERT_EQ(0, s.pop());
	for (int i = 0; i < 5; ++i) {
		s.push(i);
	}
	for (int i = 0; i < 5; ++i) {
		ASSERT_EQ(i, s.pop());
	}

	ASSERT_EQ(0, s.pop());
	ASSERT_EQ(0, s.pop());

	Queue<std::string> ss;

	ASSERT_EQ(true, ss.pop().empty());  // Check if string is empty
	std::string arr[5] = {"aaa", "bbb", "ccc", "ddd", "eeeeee"};

	for (int i = 0; i < 5; ++i) {
		ss.push(arr[i]);
	}

	for (int i = 0; i < 5 ; ++i) {
		ASSERT_EQ(arr[i], ss.pop());
	}

	ASSERT_EQ(true, ss.pop().empty());
	ASSERT_EQ(true, ss.pop().empty());
}

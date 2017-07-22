#include <vector>
#include <utility>

#include "gtest/gtest.h"
#include "union_find.hpp"

TEST(UnionFindTest, small_graph) {
	std::vector<std::pair<int, int> > inputs = {{4, 3}, {3, 8}, {6, 5}, {9, 4},
	 					{2, 1}, {8, 9}, {5, 0}, {7, 2}, {6, 1}, {1, 0}, {6, 7}};

	UnionFind uf(10);
	for (int i = 0; i < 3; ++i) {
		uf.union_nodes(inputs[i].first, inputs[i].second);
	}
	ASSERT_EQ(7, uf.count());
	ASSERT_EQ(true, uf.connected(3, 8));
	ASSERT_EQ(true, uf.connected(3, 4));
	ASSERT_EQ(true, uf.connected(6, 5));
	ASSERT_EQ(false, uf.connected(1, 2));
	ASSERT_EQ(false, uf.connected(3, 2));
	ASSERT_EQ(4, uf.find(3));
	ASSERT_EQ(4, uf.find(8));
	ASSERT_EQ(6, uf.find(6));
	ASSERT_EQ(4, uf.find(4));
	ASSERT_EQ(6, uf.find(5));

	for (int i = 3; i < 7; ++i) {
		uf.union_nodes(inputs[i].first, inputs[i].second);
	}
	ASSERT_EQ(4, uf.count());
	ASSERT_EQ(true, uf.connected(9, 8));
	ASSERT_EQ(true, uf.connected(0, 6));
	ASSERT_EQ(true, uf.connected(1, 2));
	ASSERT_EQ(true, uf.connected(7, 7));
	ASSERT_EQ(true, uf.connected(3, 9));
	ASSERT_EQ(false, uf.connected(2, 4));
	ASSERT_EQ(false, uf.connected(6, 9));
	ASSERT_EQ(2, uf.find(1));
	ASSERT_EQ(4, uf.find(9));
	ASSERT_EQ(6, uf.find(0));
	ASSERT_EQ(7, uf.find(7));

	for (int i = 7; i < 10; ++i) {
		uf.union_nodes(inputs[i].first, inputs[i].second);
	}
	ASSERT_EQ(2, uf.count());
	ASSERT_EQ(true, uf.connected(7, 6));
	ASSERT_EQ(true, uf.connected(1, 5));
	ASSERT_EQ(true, uf.connected(0, 2));
	ASSERT_EQ(false, uf.connected(9, 7));
	ASSERT_EQ(true, uf.connected(1, 6));
	ASSERT_EQ(false, uf.connected(5, 4));
	ASSERT_EQ(false, uf.connected(7, 3));
	ASSERT_EQ(6, uf.find(1));
	ASSERT_EQ(6, uf.find(7));
	ASSERT_EQ(6, uf.find(2));
	ASSERT_EQ(4, uf.find(8));
}

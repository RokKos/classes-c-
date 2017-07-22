#ifndef _SRC_UNION_FIND_HPP_
#define _SRC_UNION_FIND_HPP_

// System includes

// User includes

/**
 * @file union_find.hpp
 * @author Rok Kos <kosrok97@gmail.com>
 * @brief Class that represent union find implemented with weighted quick-union..
 */

class UnionFind {
private:
	int* component;
	int* size_of_tree;
	int component_count;

public:
	// Constructor
	UnionFind(int N);
	// Destructor
	~UnionFind();

	void union_nodes(int p, int q);  // Connect two nodes
	int find(int p) const;  // Find to which component node belongs
	bool connected(int p, int q) const;  //
	int count() const;

};

#endif  // _SRC_UNION_FIND_HPP_

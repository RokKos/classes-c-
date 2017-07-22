#include "union_find.hpp"

UnionFind::UnionFind(int N) {
	component = new int[N];
	size_of_tree = new int[N];
	for (int i = 0; i < N; ++i) {
		component[i] = i;
		size_of_tree[i] = 1;
	}

	component_count = N;
}

UnionFind::~UnionFind() {
	delete[] component;
	delete[] size_of_tree;
}

int UnionFind::find(int p) const {
	while (p != component[p]) {
		p = component[p];
	}
	return component[p];
}

void UnionFind::union_nodes(int p, int q) {
	int component_p = find(p);
	int component_q = find(q);

	if (component_q != component_p) {
		if (size_of_tree[component_p] >= size_of_tree[component_q]) {
			size_of_tree[component_p] += size_of_tree[component_q];
			component[component_q] = component_p;
		} else {
			size_of_tree[component_q] += size_of_tree[component_p];
			component[component_p] = component_q;
		}
		component_count--;
	}
}

bool UnionFind::connected(int p, int q) const {
	return find(p) == find(q);
}

int UnionFind::count() const {
	return component_count;
}

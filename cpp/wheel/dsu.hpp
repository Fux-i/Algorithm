#pragma once
#include <numeric>
#include <vector>

class dsu {
	std::vector<size_t> parents, sizes;

public:
	// the actual size will +1 (assume numbers begin from 1)
	explicit dsu(const size_t size) : parents(size + 1), sizes(size + 1, 1) {
		std::iota(parents.begin(), parents.end(), 0);
	}

	size_t find(const size_t x) {
		return parents[x] == x ? x : parents[x] = find(parents[x]);
	}

	bool same(const size_t x, const size_t y) {
		return find(x) == find(y);
	}

	void unite(size_t x, size_t y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (sizes[x] < sizes[y]) std::swap(x, y);
		parents[y] = x;
		sizes[x] += sizes[y];
	}
};

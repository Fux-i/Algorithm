#pragma once
#include <vector>

template<typename T>
class fenwick {
	std::vector<T> nums;
	size_t n;
	std::vector<T> tree;

	T lowbit(size_t x) {
		return x & -x;
	}

	T pre_sum(size_t i) {
		T sum = 0;
		for (; i > 0; i -= lowbit(i)) {
			sum += tree[i];
		}
		return sum;
	}
public:
	fenwick(std::vector<T> &init) : nums(init), n(init.size()) {
		tree.assign(n + 1, 0);
		for (size_t i = 0; i < n; i++) {
			T val = nums[i];
			size_t j = i + 1;
			for (; j < n + 1; j += lowbit(j)) {
				tree[j] += val;
			}
		}
	}

	void update(size_t idx, T val) {
		T delta = val - nums[idx];
		nums[idx] = val;
		for (size_t i = idx + 1; i < n + 1; i += lowbit(i)) {
			tree[i] += delta;
		}
	}

	T range_sum(T l, T r) {
		return pre_sum(r + 1) - pre_sum(l);
	}
};

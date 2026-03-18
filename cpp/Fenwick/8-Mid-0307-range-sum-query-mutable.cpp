#include <bits/stdc++.h>

using namespace std;
using ll = int;

class fenwick {
	std::vector<ll> nums;
	ll n;
	std::vector<ll> tree;

	ll lowbit(ll x) {
		return x & -x;
	}

	ll pre_sum(ll i) {
		ll sum = 0;
		for (; i > 0; i -= lowbit(i)) {
			sum += tree[i];
		}
		return sum;
	}
public:
	fenwick(std::vector<ll> &init) : nums(init), n(init.size()) {
		tree.assign(n + 1, 0);
		for (ll i = 0; i < n; i++) {
			ll val = nums[i];
			ll j = i + 1;
			for (; j < n + 1; j += lowbit(j)) {
				tree[j] += val;
			}
		}
	}

	void update(ll idx, ll val) {
		ll delta = val - nums[idx];
		nums[idx] = val;
		for (ll i = idx + 1; i < n + 1; i += lowbit(i)) {
			tree[i] += delta;
		}
	}

	ll range_sum(ll l, ll r) {
		return pre_sum(r + 1) - pre_sum(l);
	}
};

class NumArray {
	fenwick tree;
public:
	NumArray(vector<int>& nums) : tree(nums) {
	}

	void update(int index, int val) {
		tree.update(index, val);
	}

	int sumRange(int left, int right) {
		return tree.range_sum(left, right);
	}
};

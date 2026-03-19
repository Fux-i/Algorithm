#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class fenwick {
	vector<ll> nums;
	ll n;
	vector<array<int, 6>> tree;
	unordered_map<ll, int> cache;

	int get_depth(ll x) {
		if (cache.contains(x)) return cache[x];
		if (x == 1) return 0;
		int d = 0, y = x;
		while (x != 1) {
			x = __popcount(x);
			d++;
		}
		cache[y] = d;
		return d;
	}

	int pre_sum(ll i, int k) {
		int sum = 0;
		for (; i > 0 ; i &= i - 1) {
			sum += tree[i][k];
		}
		return sum;
	}
public:
	fenwick(vector<ll> &init) : nums(init), n(nums.size()), tree(n + 1) {
		for (ll i = 0; i < n; ++i) {
			int pop = get_depth(nums[i]);
			for (ll j = i + 1; j <= n; j += j & -j) {
				tree[j][pop]++;
			}
		}
	}

	void update(ll idx, ll val) {
		ll old = nums[idx];
		if (old == val) return;
		nums[idx] = val;
		int pop1 = get_depth(old);
		int pop2 = get_depth(val);
		for (ll i = idx + 1; i <= n; i += i & -i) {
			tree[i][pop1]--;
			tree[i][pop2]++;
		}
	}

	int qualified(ll l, ll r, int k) {
		return pre_sum(r + 1, k) - pre_sum(l, k);
	}
};
class Solution {
public:
	vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
		fenwick t(nums);
		vector<int> ans;
		ans.reserve(queries.size());
		for (auto &q : queries) {
			if (q[0] == 1) ans.push_back(t.qualified(q[1], q[2], q[3]));
			else t.update(q[1], q[2]);
		}
		return ans;
	}
};
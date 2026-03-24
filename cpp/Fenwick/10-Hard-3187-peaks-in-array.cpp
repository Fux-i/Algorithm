#include <bits/stdc++.h>
using namespace std;

class fenwick {
	vector<int> nums;
	int n;
	vector<bool> peaks;
	vector<int> tree;

	int pre_sum(int i) const {
		int sum = 0;
		for (; i > 0; i &= i - 1)
			sum += tree[i];
		return sum;
	}
public:
	fenwick(vector<int> &init) : nums(init), n(nums.size()), peaks(n, false), tree(n + 1, 0) {
		for (int i = 1; i < n - 1; ++i)
			if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
				peaks[i] = true;
				for (int j = i + 1; j <= n; j += j & -j)
					tree[j] += 1;
			}
	}

	int range_count(int l, int r) const {
		if (l == r) return 0;
		return pre_sum(r) - pre_sum(l + 1);
	}

	void update(int idx, int val) {
		if (nums[idx] == val) return;
		nums[idx] = val;
		const vector<int> indices = {idx - 1, idx, idx + 1};
		for (int i = 0; i < 3; ++i) {
			const int c_idx = indices[i];
			if (c_idx < 1 || c_idx >= n - 1) continue;

			const bool is_peak = nums[c_idx - 1] < nums[c_idx] && nums[c_idx] > nums[c_idx + 1];
			if (peaks[c_idx] == is_peak) continue;
			peaks[c_idx] = is_peak;
			const int diff = is_peak ? 1 : -1;
			for (int j = c_idx + 1; j <= n; j += j & -j)
				tree[j] += diff;
		}
	}
};

class Solution {
public:
	vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
		fenwick t(nums);
		vector<int> ans;
		ans.reserve(nums.size());
		for (auto &q : queries) {
			if (q[0] == 1) ans.push_back(t.range_count(q[1], q[2]));
			else t.update(q[1], q[2]);
		}
		return ans;
	}
};

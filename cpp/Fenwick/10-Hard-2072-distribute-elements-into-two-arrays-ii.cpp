#include <bits/stdc++.h>
using namespace std;

class fenwick{
	int n;
	vector<int> tree;
public:
	fenwick(int n) : n(n), tree(n + 1) {}

	void add(int idx){
		for(int i = idx; i <= n; i += i & -i){
			tree[i]++;
		}
	}

	int pre_sum(int idx){
		int sum = 0;
		for(int i = idx; i > 0; i &= i - 1){
			sum += tree[i];
		}
		return sum;
	}
};

class Solution {
public:
	vector<int> resultArray(vector<int>& nums) {
		int n = nums.size();

		vector<int> sorted(nums);
		ranges::sort(sorted);
		sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
		int m = sorted.size();
		fenwick t1(m), t2(m);

		vector<int> a{nums[0]}, b{nums[1]};
		t1.add(ranges::lower_bound(sorted, nums[0]) - sorted.begin() + 1);
		t2.add(ranges::lower_bound(sorted, nums[1]) - sorted.begin() + 1);
		for(int i = 2; i < n; ++i){
			int val  = nums[i];
			int idx = ranges::lower_bound(sorted, val) - sorted.begin() + 1;
			int cnt1 = a.size() - t1.pre_sum(idx);
			int cnt2 = b.size() - t2.pre_sum(idx);
			if(cnt1 > cnt2 || cnt1 == cnt2 && a.size() <= b.size()){
				a.push_back(val);
				t1.add(idx);
			} else {
				b.push_back(val);
				t2.add(idx);
			}
		}
		a.insert(a.end(), b.begin(), b.end());
		return a;
	}
};
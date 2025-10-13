#include <vector>

class Solution
{
public:
	std::vector<int> one;
	std::vector<std::vector<int>> ans;

	std::vector<std::vector<int>> subsets(std::vector<int>& nums)
	{
		backTracing(0, nums);
		return ans;
	}

	void backTracing(size_t idx, std::vector<int>& nums)
	{
		if (idx == nums.size())
		{
			ans.push_back(one);
			return;
		}

		backTracing(idx + 1, nums);

		one.push_back(nums[idx]);
		backTracing(idx + 1, nums);
		one.pop_back();
	}
};

/*
class Solution {
public:
	vector<int> t;
	vector<vector<int>> ans;

	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		for (int mask = 0; mask < (1 << n); ++mask) {
			t.clear();
			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					t.push_back(nums[i]);
				}
			}
			ans.push_back(t);
		}
		return ans;
	}
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/subsets/solutions/420294/zi-ji-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <algorithm>

class Solution
{
public:
	std::vector<int> one;
	std::vector<std::vector<int>> ans;

	std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());
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

		if (!(idx > 0 && !one.empty() && one.back() == nums[idx]))
			backTracing(idx + 1, nums);

		one.push_back(nums[idx]);
		backTracing(idx + 1, nums);
		one.pop_back();
	}
};
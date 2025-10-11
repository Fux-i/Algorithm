#include <algorithm>
#include <vector>

class Solution {
	int sum = 0;
	std::vector<int> one;
	std::vector<std::vector<int>> ret;
public:
	std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		rec(candidates, target, 0);
		return ret;
	}

	void rec(std::vector<int>& nums, int target, int idx)
	{
		if (sum == target)
		{
			ret.push_back(one);
			return;
		}
		
		for (int i = idx; i < nums.size(); i++)
		{
			if (i > idx && nums[i] == nums[i-1]) continue;
			if (sum + nums[i] > target) break;
			
			int num = nums[i];
			
			one.push_back(num);
			sum += num;
			
			rec(nums, target, i);
			
			sum -= num;
			one.pop_back();
		}
	}
};
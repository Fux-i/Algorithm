#include <vector>

class Solution {
	int sum = 0;
	std::vector<int> one;
	std::vector<std::vector<int>> ret;
public:
	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        rec(candidates, target, 0);
		return ret;
	}

	void rec(std::vector<int>& nums, int target, int idx)
	{
		for (int i = idx; i < nums.size(); i++)
		{
			int num = nums[i];
			
			one.push_back(num);
			sum += num;
			if (sum == target)
				ret.push_back(one);
			if (sum < target)
				rec(nums, target, i);
			
			sum -= num;
			one.pop_back();
		}
	}
};
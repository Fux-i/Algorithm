#include <vector>

class Solution
{
public:
	int jump(std::vector<int>& nums)
	{
		size_t  size = nums.size(),
				max_pos = 0,
				end = 0,
				step = 0;
		
		for (size_t i = 0; i < size - 1; i++)
		{
			max_pos = std::max(max_pos, i + nums[i]);
			if (i == end)
			{
				end = max_pos;
				step++;
			}
		}
		return step;
	}
};

	/* 超时
	int dfs(std::vector<int>& nums, size_t idx, int step)
	{
		if (idx >= size - 1) return step;

		int len = nums[idx];
		int min_step = INT32_MAX;
		for (int i = 1; i <= len; i++)
			min_step = std::min(min_step, dfs(nums, idx + i, step + 1));

		return min_step;
	}
	*/
#include <algorithm>
#include <vector>

class Solution
{
public:
	int largestSumAfterKNegations(std::vector<int>& nums, int k)
	{
		std::sort(nums.begin(), nums.end());
		
		int sum = 0;
		size_t  size = nums.size();
		
		for (size_t i = 0; i < size; i++)
		{
			int num = nums[i];
			if (k == 0)
			{
				sum += num;
				continue;
			}
			if (num < 0)
			{
				sum += -num;
				k--;
				continue;
			}
			if (i > 0 && nums[i-1] < 0)	// 首次遇到最小的非负数
			{
				if (-nums[i-1] < num)
				{
					if (k % 2 != 0) sum += 2 * nums[i-1];
					sum += num;
				}
				else
				{
					if (k % 2 != 0) sum += -num;
					else sum += num;
				}
				k = 0;
			}
			else
			{
				if (k % 2 != 0) sum += -num;
				else sum += num;
				k = 0;
			}
		}
		if (k > 0 && k % 2 != 0)
				sum += 2 * nums[size - 1];
		
		return sum;
	}
};
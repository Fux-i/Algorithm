#include <algorithm>
#include <cstdint>
#include <vector>

class Solution
{
public:
	int maxSubArray(std::vector<int>& nums)
	{
		int result = INT32_MIN;
		int count = 0;
		for (const int num : nums)
		{
			count += num;
			result = std::max(count, result);
			count = std::max(count, 0);
		}
		return result;
	}
};
#include <vector>

class Solution
{
public:
	int minSubArrayLen(int target, std::vector<int>& nums)
	{
		int size = nums.size();
		std::vector<std::vector<int>> dp(size, std::vector<int>(size));
		int min_length = INT_MAX;
		for (int i = 0; i < size; i++)
		{
			dp[i][i] = nums[i];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (j > i)
				{
					dp[i][j] = dp[i][j-1] + dp[j][j];
				}
				if (dp[i][j] >= target)
				{
					auto length = j - i + 1;
					min_length = min_length < length ? min_length : length;
				}
			}
		}

		return min_length;
	}
};
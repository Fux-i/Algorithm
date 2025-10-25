#include <vector>

class Solution
{
public:
	int minCostClimbingStairs(std::vector<int>& cost)
	{
		int size = cost.size() + 1;
		std::vector<int> dp(size, 0);

		for (int i = 2; i < size; i++)
			dp[i] = std::min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
		return dp[size - 1];
	}
};
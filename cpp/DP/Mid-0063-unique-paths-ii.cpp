#include <vector>

class Solution
{
public:
	int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		
		std::vector<int> dp(n);
		
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (obstacleGrid[i][j] == 1) dp[j] = 0;
				else if (i == 0) dp[j] = j == 0 ? 1 : dp[j - 1];
				else if (j == 0) dp[j] = dp[j];
				else dp[j] += dp[j - 1];
			}

		return dp[n - 1];
	}
};
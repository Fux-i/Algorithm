#include <vector>

class Solution
{
public:
	int numTrees(int n)
	{
		if (n == 1) return 1;
		std::vector<int> dp(n + 1, 1);
		for (int i = 2; i <= n; i++)
		{
			int num = 0;
			for (int j = 0; j < i; j++)
				num += dp[j] * dp[i - 1 - j];
			dp[i] = num;
		}
		return dp[n];
	}
};
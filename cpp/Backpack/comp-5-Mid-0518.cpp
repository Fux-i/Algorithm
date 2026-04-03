#include <vector>
using namespace std;

class Solution
{
public:
	int change(int amount, vector<int>& coins)
	{
		if (amount == 0) return 1;
		vector<size_t> dp(amount+1, 0);	// 测试用例有问题.. 用int会overflow
		dp[0] = 1;
		for (int coin : coins)
			for (size_t j = coin; j <= amount; j++)
				dp[j] = dp[j] + dp[j-coin];
		return dp[amount];
	}
	/*
	int change(int amount, vector<int>& coins)
	{
		if (amount == 0) return 1;
		
		size_t size = coins.size();
		vector dp(size+1, vector<size_t>(amount+1, 0));
		for (size_t i = 0; i < size; i++)
		{
			size_t coin = coins[i];
			for (size_t j = 1; j <= amount; j++)
			{
				if (j == coin) dp[i+1][j] = dp[i][j] + 1;
				else if (j < coin) dp[i+1][j] = dp[i][j];
				else dp[i+1][j] = dp[i][j] + dp[i+1][j-coin];
			}
		}
		return dp[size][amount];
	}*/
};
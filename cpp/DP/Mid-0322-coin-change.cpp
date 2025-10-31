#include <vector>
using namespace std;

class Solution
{
public:
	int coinChange(vector<int>& coins, int amount)
	{
		vector dp(amount + 1, INT_MAX / 2);
		dp[0] = 0;
		for (int coin : coins)
			for (int i = coin; i <= amount; i++)
				dp[i] = min(dp[i], dp[i - coin] + 1);
		return dp[amount] < INT_MAX / 2 ? dp[amount] : -1;
	}
};
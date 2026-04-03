#include <vector>
using namespace std;

class Solution
{
public:
	int numSquares(int n)
	{
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int j = 1; j <= n; j++)
			for (int i = 1; i * i <= j; i++)
				dp[j] = min(dp[j], dp[j - i * i] + 1);
		return dp[n];
	}
};
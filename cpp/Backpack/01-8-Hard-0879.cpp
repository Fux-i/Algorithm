#include <vector>
using namespace std;

class Solution {
	static constexpr int MOD = 1e9 + 7;
public:
	int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
		vector<vector<int> > dp(n + 1, vector<int>(minProfit + 1, 0));
		for (int i = 0; i < n + 1; ++i) dp[i][0] = 1;

		int num_task = group.size();
		for (int i = 0; i < num_task; ++i) {
			int num_member = group[i], earn = profit[i];
			for (int j = n; j >= num_member; --j) {
				for (int k = minProfit; k >= 0; --k) {
					dp[j][k] = (dp[j][k] + dp[j - num_member][max(0, k - earn)]) % MOD;
				}
			}
		}
		return dp[n][minProfit];
	}
};

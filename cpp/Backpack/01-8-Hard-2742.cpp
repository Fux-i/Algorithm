#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
	int paintWalls(vector<int> &cost, vector<int> &time) {
		int n = cost.size();
		vector<int> dp(n + 1,INT_MAX / 2);	// dp[i]: i walls need dp[i] at least
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			int t = time[i], c = cost[i];
			int cnt = t + 1;
			for (int j = n; j >= 0; j--) {
				dp[j] = min(dp[j], dp[max(0, j - cnt)] + c);
			}
		}
		return dp[n];
	}
};
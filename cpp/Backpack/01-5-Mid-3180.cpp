#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
	int maxTotalReward(vector<int> &rewardValues) {
		ranges::sort(rewardValues);
		rewardValues.erase(ranges::unique(rewardValues).begin(), rewardValues.end());
		int max_val = rewardValues.back();
		vector<bool> dp(2 * max_val, false);
		dp[0] = true;
		for (int x: rewardValues)
			for (int i = x - 1; i >= 0; i--)
				if (dp[i]) dp[i + x] = true;
		for (int i = 2 * max_val - 1; i >= 0; i--)
			if (dp[i]) return i;
		return 0;
	}
};

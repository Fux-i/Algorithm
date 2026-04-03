#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
	vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
		int n = nums.size();
		vector<bool> ans(n, false);
		ranges::sort(nums);
		bitset<4'001> dp{};
		dp[0] = true;

		int i = 0;
		for (int x = 1; x <= n; ++x) {
			while (i < n && nums[i] == x) {
				dp |= dp << x;
				i++;
			}
			for (int j = 0; j <= min(n - i, k / x); ++j) {
				if (dp[k - j * x]) {
					ans[x - 1] = true;
					break;
				}
			}
		}
		return ans;
	}
};
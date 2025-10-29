#include <numeric>
#include <vector>
#include <bitset>

class Solution
{
public:
	int findTargetSumWays(std::vector<int>& nums, int target)
	{
		int s = std::accumulate(nums.begin(), nums.end(), 0) - abs(target);
		if (s < 0 || s % 2)
			return 0;

		int m = s / 2; // 背包容量
		std::vector<int> f(m + 1);
		f[0] = 1;
		for (int x : nums)
			for (int c = m; c >= x; c--)
				f[c] += f[c - x];
		return f[m];
	}
};
#include <vector>
using namespace std;

class Solution
{
public:
	int lengthOfLIS(vector<int>& nums)
	{
		auto end = nums.begin();
		for (int x : nums)
		{
			auto it = lower_bound(nums.begin(), end, x);
			*it = x;
			if (it == end)  // >=x 的 g[j] 不存在
				++end;
		}
		return end - nums.begin();
	}
};

/*class Solution
{
public:
	int lengthOfLIS(vector<int>& nums)
	{
		int size = static_cast<int>(nums.size());
		int ans = 1;
		vector<int> dp(size, 1);
		for (int i = 1; i < size; i++)
		{
			int newVal = nums[i];
			if (newVal == nums[i-1])
			{
				dp[i] = dp[i-1];
				continue;
			}
			
			int newCount = 1;
			for (int j = i - 1; j >= 0; j--)
				if (nums[i] > nums[j])
					newCount = max(newCount, dp[j] + 1);
			
			dp[i] = newCount;
			ans = max(newCount, ans);
		}
		return ans;
	}
};*/
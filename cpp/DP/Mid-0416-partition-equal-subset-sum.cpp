#include <vector>
#include <bitset>
#include <numeric>


class Solution
{
public:
	bool canPartition(std::vector<int>& nums)
	{
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2)
			return false;
		sum /= 2;

		std::bitset<10001> set; // sum(nums[i]) / 2 <= 10000
		set[0] = true;
		for (int x : nums)
			set |= set << x;

		return set[sum]; // 判断 f 中第 sum 位是否为 1
	}
};
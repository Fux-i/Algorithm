#include <unordered_map>
#include <vector>

class Solution
{
public:
	int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3,
	                 std::vector<int>& nums4)
	{
		std::unordered_map<int, int> countAB;
		for (int u : nums1)
			for (int v : nums2)
				++countAB[u + v];
		int ans = 0;
		for (int u : nums3)
			for (int v : nums4)
				if (countAB.find(-u - v) != countAB.end())
					ans += countAB[-u - v];
		return ans;
	}
};
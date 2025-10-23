#include <vector>
#include <algorithm>
class Solution
{
public:
	std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
	{
		std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b)
			{
				return a[0] < b[0];
			});
		std::vector<std::vector<int>> ans{};
		int last_end = -1, last_start = -1;
		
		for (auto cu : intervals)
		{
			if (cu[1] <= last_end)	// 被包含
				continue;
			if (cu[0] > last_end)	// 无重叠
			{
				ans.push_back(cu);
				last_start = cu[0];
				last_end = cu[1];
			}
			else	// 有重叠
			{
				ans.pop_back();
				ans.push_back({last_start, cu[1]});
				last_end = cu[1];
			}
		}

		return ans;
	}
};
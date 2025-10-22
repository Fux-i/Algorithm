#include <algorithm>
#include <vector>

class Solution
{
public:
	int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
	{
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b)
        {
	        return a[1] < b[1];
        });

		int pos = intervals[0][1];
		int ans = 0;
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i][0] < pos) ans++;
			else pos = intervals[i][1];
		}
		return ans;
	}
};
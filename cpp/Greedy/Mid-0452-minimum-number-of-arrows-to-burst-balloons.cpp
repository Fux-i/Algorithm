#include <algorithm>
#include <vector>

class Solution
{
public:
	int findMinArrowShots(std::vector<std::vector<int>>& points)
	{
		std::sort(points.begin(), points.end(), [](std::vector<int>& a, std::vector<int>& b)
		{
			if (a[0] == b[0]) return a[1] < b[1];
			return a[0] < b[0];
		});
		
		int pos = points[0][1];
		int ans = 1;

		for (auto one : points)
		{
			if (one[0] > pos)
			{
				pos = one[1];
				ans++;
			}
		}

		return ans;
	}
};
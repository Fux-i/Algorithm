#include <algorithm>
#include <vector>

class Solution
{
public:
	std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people)
	{
		std::sort(people.begin(), people.end(), [](const std::vector<int>& u, const std::vector<int>& v)
		{
			return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
		});
		int length = people.size();
		std::vector<std::vector<int>> ans;
		for (int i = 0; i < length; ++i)
		{
			if (people[i][1] >= i)
				ans.push_back(people[i]);
			else
				ans.insert(ans.begin() + people[i][1], people[i]);
		}
		return ans;
	}
};
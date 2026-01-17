#include <queue>
#include <unordered_map>
#include <vector>

class Solution
{
public:
	static bool cmp(std::pair<int, int>& a, std::pair<int, int>& b)
	{
		return a.second > b.second;
	}

	std::vector<int> topKFrequent(std::vector<int>& nums, int k)
	{
		std::unordered_map<int, int> map;
		std::priority_queue<
			std::pair<int, int>,
			std::vector<std::pair<int, int>>,
			decltype(&cmp)
		> q{cmp};
		int count = 0;
		for (int& num : nums)
			map[num]++;

		for (auto& pair : map)
		{	// p: {element, frequency}
			if (count < k)
			{
				q.emplace(pair);
				count++;
			}
			else
			{
				std::pair<int, int> min = q.top();
				if (pair.second <= min.second)
					continue;
				q.pop();
				q.emplace(pair);
			}
		}

		std::vector<int> result;
		while (!q.empty())
		{
			result.emplace_back(q.top().first);
			q.pop();
		}
		return result;
	}
};
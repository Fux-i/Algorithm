#include <unordered_map>
#include <vector>

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		std::unordered_map<int, int> map{};

		for (int i = 0; i < nums.size(); i++)
		{
			int sup = target - nums[i];
			if (map.find(sup) != map.end())
				return {i, map[sup]};

			map.insert({nums[i], i});
		}

		return {};
	}
};
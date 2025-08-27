#include <unordered_set>
#include <vector>

class Solution
{
public:
	std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::unordered_set<int> set{}, res{};
		for (int n : nums1)
			set.insert(n);
		for (int n : nums2)
		{
			if (set.find(n) != set.end())
				res.insert(n);
			
		}

		std::vector<int> r{};
		r.reserve(res.size());
		for (int n : res)
			r.emplace_back(n);
		return r;
	}
};
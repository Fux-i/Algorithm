#include <vector>
#include <string>
#include <unordered_map>
class Solution {
public:
	std::vector<int> partitionLabels(std::string s) {
        std::unordered_map<char, int> map{};
		std::vector<int> ans{};
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); i++)
			map[s[i]] = i;
		
		for (int i = 0; i < s.size(); i++)
		{
			end = std::max(end, map[s[i]]);
			if (i == end)
			{
				ans.push_back(end - start + 1);
				start = end = i + 1;
			}
		}
		return ans;
	}
};
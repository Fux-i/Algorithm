#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution 
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		unordered_set<int> set(nums.begin(), nums.end());
		
		int maxLen = 0;
		for (int num : set)
		{
			if (set.contains(num - 1)) continue;
			int len = 1;
			while (set.contains(++num))
				len++;
			maxLen = max(maxLen, len);
		}
		return maxLen;
	}
};
#include <string>
#include <vector>

class Solution
{
public:
	// 击败100%，还可以用排序
	bool isAnagram(std::string s, std::string t)
	{
		if (s.length() != t.length())
		{
			return false;
		}
		std::vector<int> table(26,0);
		int count = 0;
		for (char c : s)
		{
			int index = c - 'a';
			if (table[index] == 0)
				count++;
			table[index]++;
		}
		for (auto c : t)
		{
			int index = c - 'a';
			table[index]--;
			if (table[index] == 0)
				count--;
		}
		if (count == 0)
			return true;
		return false;
	}
};
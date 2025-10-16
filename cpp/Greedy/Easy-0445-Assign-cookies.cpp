#include <vector>
#include <algorithm>

class Solution
{
public:
	int findContentChildren(std::vector<int>& g, std::vector<int>& s)
	{
		std::sort(g.begin(), g.end(), [](int a, int b){ return a > b; });
		std::sort(s.begin(), s.end(), [](int a, int b){ return a > b; });
		int sizeG = g.size();
		int sizeS = s.size();
		int i = 0;
		int j = 0;
		for ( ;i < sizeG && j < sizeS; i++)
		{
			if (g[i] <= s[j]) j++;
		}
		return j;
	}
};
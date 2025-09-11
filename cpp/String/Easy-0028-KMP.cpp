#include <string>
#include <vector>

class Solution
{
public:
	int strStr(std::string txt, std::string pattern)
	{
		int n = txt.size(), m = pattern.size();
		if (m == 0)
			return 0;
		
		// 构建 Next
		std::vector<int> next(m);
		next[0] = -1;
		if (m > 1)
			next[1] = 0;
		for (int i = 2, j = 0; i < m;)
		{
			if (pattern[i-1] == pattern[j])
				next[i++] = ++j;
			else if (j != 0)
				j = next[j];
			else
				next[i++] = 0;
		}
		// 开始匹配
		int x = 0, y = 0;
		while (x < n && y < m)
		{
			if (txt[x] == pattern[y])
			{
				x++;
				y++;
			}
			else if (y != 0)
				y = next[y];
			else
				x++;
		}
		return y == m ? x - y : -1;
	}
};
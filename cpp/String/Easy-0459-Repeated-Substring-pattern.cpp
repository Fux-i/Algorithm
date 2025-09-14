#include <string>
#include <vector>

class Solution
{
public:
	bool repeatedSubstringPattern(std::string s)
	{
		auto size = s.size();
		return kmp((s + s).substr(1, 2 * size - 1), s);
		// return (s + s).find(s, 1) != s.size();
	}

	bool kmp(std::string txt, std::string pattern)
	{
		int n = txt.size(), m = pattern.size();
		std::vector<int> next(m);
		next[0] = -1;
		if (m > 1)
			next[1] = 0;
		for (int i = 2, j = 0; i < m;)
		{
			if (pattern[i - 1] == pattern[j])
				next[i++] = ++j;
			else if (j != 0)
				j = next[j];
			else
				i++;
		}

		int i = 0, j = 0;
		for (; i < n && j < m;)
		{
			if (txt[i] == pattern[j])
			{
				i++;
				j++;
			}
			else if (j != 0)
				j = next[j];
			else
				i++;
		}

		return j == m;
	}
};
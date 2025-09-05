#include <string>

class Solution
{
public:
	std::string reverseStr(std::string s, int k)
	{
		auto size = s.size();
		for (int i = 0; i < size; i += (2 * k))
		{
			if (i + k > size)
				std::reverse(s.begin() + i, s.end());
			else
				std::reverse(s.begin() + i, s.begin() + i + k);
		}
		return s;
	}
};
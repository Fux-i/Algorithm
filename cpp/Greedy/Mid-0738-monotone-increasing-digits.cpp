#include <string>

class Solution
{
public:
	int monotoneIncreasingDigits(int n)
	{
		std::string strN = std::to_string(n);
		int i = 1;
		for (; i < strN.length() && strN[i - 1] <= strN[i]; i++);
		
		if (i < strN.length())
		{
			while (i > 0 && strN[i - 1] > strN[i])
			{
				strN[i - 1] -= 1;
				i -= 1;
			}
			for (i += 1; i < strN.length(); ++i)
				strN[i] = '9';
		}
		return std::stoi(strN);
	}
};
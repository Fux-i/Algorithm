#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool wordBreak(string s, vector<string>& wordDict)
	{
		int sz = s.size();
		vector<bool> dp(sz + 1, 0);
		dp[0] = true;
		for (int i = 0; i < sz; ++i)
		{
			if (!dp[i])
				continue;
			for (const auto& j : wordDict)
			{
				int len = j.size();
				string str = s.substr(i, len);
				if (str == j)
				{
					dp[i + len] = true;
				}
			}
		}
		return dp[sz];
	}
};
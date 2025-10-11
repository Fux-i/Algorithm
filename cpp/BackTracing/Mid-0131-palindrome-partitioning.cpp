#include <string>
#include <vector>

class Solution
{
	size_t size;
	std::string str;
	std::vector<std::vector<bool>> dp_;
	std::vector<std::string> one;
	std::vector<std::vector<std::string>> ret;
public:
	std::vector<std::vector<std::string>> partition(std::string s)
	{
		size = s.size();
		str = std::move(s);
		std::vector<std::vector<bool>> dp(size, std::vector<bool>(size, false));
		for (size_t i = 0; i < size; i++)
			dp[i][i] = true;
		for (size_t len = 1; len < size; len++)
			for (size_t i = 0; i + len < size; i++)	// 起始字符位置
			{
				if (len == 1 || len == 2)
					dp[i][i + len] = str[i] == str[i + len];
				else
					dp[i][i + len] = str[i] == str[i + len] && dp[i + 1][i + len - 1];
			}
		dp_ = std::move(dp);

		rec(0);

		return ret;
	}

	void rec(size_t idx)
	{
		if (idx >= size)
		{
			ret.push_back(one);
			return;
		}

		for (size_t k = idx; k < size; k++)
		{
			if (dp_[idx][k])
			{
				one.push_back(str.substr(idx, k - idx + 1));
				rec(k + 1);
				one.pop_back();
			}
		}
	}
};
#include <string>
#include <vector>

class Solution
{
public:
	std::vector<std::string> restoreIpAddresses(std::string s)
	{
		std::vector<std::string> result;
		std::string current;
		backtrack(s, 0, 0, current, result);
		return result;
	}
private:
	void backtrack(const std::string& s, int start, int dots,
	               std::string& current, std::vector<std::string>& result)
	{
		// 终止条件
		if (dots == 3)
		{
			if (isValidSegment(s.substr(start)))
				result.push_back(current + s.substr(start));
			return;
		}

		// 尝试1-3个字符
		for (int len = 1; len <= 3 && start + len < s.size(); ++len)
		{
			std::string segment = s.substr(start, len);
			if (isValidSegment(segment))
			{
				std::string newCurrent = current + segment + ".";
				backtrack(s, start + len, dots + 1, newCurrent, result);
			}
		}
	}

	bool isValidSegment(const std::string& segment)
	{
		if (segment.empty() || segment.size() > 3)
			return false;
		if (segment.size() > 1 && segment[0] == '0')
			return false;
		int num = std::stoi(segment);
		return num >= 0 && num <= 255;
	}
};
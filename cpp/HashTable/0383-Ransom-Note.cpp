#include <string>
#include <unordered_map>

class Solution
{
public:
	bool canConstruct(std::string ransomNote, std::string magazine)
	{
		std::unordered_map<char, short> map{};
		for (char c : magazine)
			map[c]++;
		for (char c : ransomNote)
		{
			if (map.find(c) == map.end())
				return false;
			if (--map[c] == -1)
				return false;
		}
		return true;
	}
};
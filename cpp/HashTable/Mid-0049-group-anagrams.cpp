#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, vector<string>> mp;
		for (string& str : strs)
		{
			string key = str;
			ranges::sort(key);
			mp[key].emplace_back(str);
		}
		vector<vector<string>> ans;
		for (auto it = mp.begin(); it != mp.end(); ++it)
			ans.emplace_back(it->second);
		return ans;
	}
};
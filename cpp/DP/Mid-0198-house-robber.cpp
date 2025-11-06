#include <vector>
using namespace std;

class Solution
{
public:
	int rob(vector<int>& nums)
	{
		int get = 0, wait = 0;
		for (int num : nums)
		{
			int newGet = wait + num;
			wait = max(wait, get);
			get = newGet;
		}
		return max(wait, get);
	}
};
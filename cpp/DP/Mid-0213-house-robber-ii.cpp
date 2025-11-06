#include <vector>
using namespace std;

class Solution
{
public:
	int rob(vector<int>& nums)
	{
		int size = nums.size();
		if (size == 1) return nums[0];
		
		int get = 0, wait = 0;
		for (int i = 0; i < size-1; i++)
		{
			int newGet = wait + nums[i];
			wait = max(wait, get);
			get = newGet;
		}
		int headMax = max(wait, get);
		
		get = 0; wait = 0;
		for (int i = 1; i < size; i++)
		{
			int newGet = wait + nums[i];
			wait = max(wait, get);
			get = newGet;
		}
		int tailMax = max(wait, get);

		return max(headMax, tailMax);
	}
};
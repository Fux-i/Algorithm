#include <vector>

class Solution
{
public:
	int wiggleMaxLength(std::vector<int>& nums)
	{
		int size = nums.size();
		int maxSubLength = 1;
		int lastDiff;
		for (int i = 1; i < size; i++)
		{
			int curDiff = nums[i] - nums[i - 1];
			if (curDiff == 0) continue;	// 相等，删一个（跳过）
				
			if (maxSubLength == 1)	// 第一个，记录差值后跳过
			{
				lastDiff = curDiff;
				maxSubLength++;
				continue;
			}
			
			if (lastDiff > 0 && curDiff > 0 || lastDiff < 0 && curDiff < 0)	// 两次差值同大
				continue;

			// 两次差值一大一小
			lastDiff = curDiff;
			maxSubLength++;
		}
		
		return maxSubLength;
	}
};
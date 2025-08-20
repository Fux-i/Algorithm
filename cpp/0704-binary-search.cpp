#include <vector>

class Solution
{
public:
	int search(std::vector<int>& nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (right - left) / 2 + left;	// 防溢出
			int num = nums[mid];
			if (num == target)
				return mid;
			else if (num > target)
				right = mid - 1;
			left = mid + 1;
		}
		return -1;
	}
};
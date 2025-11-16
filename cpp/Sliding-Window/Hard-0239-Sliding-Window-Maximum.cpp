#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        vector<int> ans = {q.top().first};
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

/* time out
class Solution {
public:
	std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
		auto size = nums.size();
		std::vector<int> res;
		res.reserve(size - k+1);
		
		int max_value = INT32_MIN;
		int index = -1;
		// int last_index = -1;
		
		for (int i = k-1; i < size; i++)
		{
			if (index > i - k)	// 上一次的最大值仍在范围内，只需比较最新值
			{
				if (max_value < nums[i]) // 最新值更大
				{
					index = i;
					max_value = nums[i];
					res.emplace_back(max_value);
				}
				else // 更新值没更大
				{
					res.emplace_back(max_value);
				}
			}
			else // 上次的最大值已不再范围内
			{
				max_value = INT32_MIN;
				for (int j = i-k+1; j <= i; j++)
				{
					if (max_value < nums[j])
					{
						index = j;
						max_value = nums[j];
					}	
				}
				res.emplace_back(max_value);
			}
		}

		return res;
	}
};
*/

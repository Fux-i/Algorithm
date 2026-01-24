#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int minPairSum(vector<int> &nums) {
		ranges::sort(nums);
		int l = 0, r = nums.size() - 1;
		int sum = 0;
		while (l < r) {
			sum = max(sum, nums[l] + nums[r]);
			++l; --r;
		}
		return sum;
	}
};

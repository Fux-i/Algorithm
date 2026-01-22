#include <vector>

using namespace std;

class Solution {
public:
	bool help(vector<int> &nums) {
		int n = nums.size();
		for (int i = 0; i < n - 1; ++i)
			if (nums[i] > nums[i + 1])
				return true;

		return false;
	}

	int minimumPairRemoval(vector<int> &nums) {
		int result = 0;
		while (help(nums)) {
			int idx = 0;
			int mn = nums[0] + nums[1];

			for (int i = 1; i + 1 < (int) nums.size(); i++) {
				int sum = nums[i] + nums[i + 1];
				if (sum < mn) {
					mn = sum;
					idx = i;
				}
			}
			nums[idx] = nums[idx] + nums[idx + 1];
			nums.erase(nums.begin() + (idx + 1));
			result++;
		}
		return result;
	}
};

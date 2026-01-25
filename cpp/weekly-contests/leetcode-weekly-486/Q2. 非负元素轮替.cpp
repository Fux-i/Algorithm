#include <vector>
using namespace std;

class Solution {
public:
	vector<int> rotateElements(vector<int> &nums, int k) {
		vector<int> ans = nums;
		vector<int> non_neg;
		for (int x: nums) {
			if (x >= 0) non_neg.push_back(x);
		}

		if (non_neg.empty()) return ans;

		int m = non_neg.size();
		k %= m;

		int idx = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] >= 0) {
				int source_idx = (idx + m + k) % m;
				ans[i] = non_neg[source_idx];
				++idx;
			}
		}

		return ans;
	}
};

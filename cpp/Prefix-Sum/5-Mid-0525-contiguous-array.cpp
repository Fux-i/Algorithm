#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	int findMaxLength(vector<int> &nums) {
		int n = nums.size();
		int ans = 0;
		unordered_map<int, int> m{};

		vector<int> v(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			int val = v[i] + (nums[i] == 1 ? 1 : -1);
			v[i + 1] = val;
			if (val == 0) {
				ans = max(ans, i + 1);
			} else {
				if (!m.contains(val)) m[val] = i;
				else ans = max(ans, i - m[val]);
			}
		}
		return ans;
	}
};

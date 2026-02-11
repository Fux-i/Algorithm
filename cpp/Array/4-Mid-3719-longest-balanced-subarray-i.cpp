#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	int longestBalanced(vector<int>& nums) {
        int n = nums.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			unordered_map<int, int> map{};
			int odd = 0, even = 0;
			for (int j = i; j < n; ++j) {
				int v = nums[j];
				if (!map.contains(v)) {
					++(v & 1 ? odd : even);
				}
				++map[v];
				if (odd == even) {
					ans = max(ans, j - i + 1);
				}
			}
		}
		return ans;
	}
};
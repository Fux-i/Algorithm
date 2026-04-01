#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubsequence(vector<int>& nums, int target) {
		vector<int> f(target + 1, INT_MIN);
		f[0] = 0;
		int s = 0;
		for (int x : nums) {
			s = min(s + x, target);
			for (int i = s; i >= x; i--) {
				f[i] = max(f[i], f[i - x] + 1);
			}
		}
		return f[target] > 0 ? f[target] : -1;
	}
};
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
	int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
		int last_num = INT_MAX;
		for (int i = n - 1; i >= 0; --i) {
			if (nums[i] >= last_num) {
				return i + 1;
			}
			last_num = nums[i];
		}
		return 0;
	}
};
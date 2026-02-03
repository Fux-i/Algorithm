#include <vector>
using namespace std;

class Solution {
public:
	bool isTrionic(vector<int> &nums) {
		if (nums[0] >= nums[1]) return false;
		int inc = 1;
		int time = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) return false;
			else if (inc * (nums[i] - nums[i - 1]) < 0) {
				inc *= -1;
				++time;
			}
		}
		return time == 2;
	}
};

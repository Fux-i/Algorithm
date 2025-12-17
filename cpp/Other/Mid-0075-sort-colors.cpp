#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        short n = nums.size();
        short p0 = 0, p2 = n - 1;
        for (short i = 0; i <= p2; ++i) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                --p2;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};

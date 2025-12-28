#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        ranges::sort(nums);
        int n = nums.size();
        int l = 0, r = -1, ans = 1;
        while (r < n - 1) {
            int val = nums[++r];
            while ((size_t)nums[l] * k < val) {
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return n - ans;
    }
};
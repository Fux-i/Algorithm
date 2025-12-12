#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int f_max = 1, f_min = 1;
        for (int x : nums) {
            if (x < 0) swap(f_max, f_min);
            f_max = max(f_max * x, x);
            f_min = min(f_min * x, x);
            ans = max(ans, f_max);
        }
        return ans;
    }
};

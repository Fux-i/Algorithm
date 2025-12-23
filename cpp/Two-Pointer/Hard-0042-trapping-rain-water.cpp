#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, pre_max = 0, suf_max = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            ans += pre_max < suf_max ? pre_max - height[left++] : suf_max - height[right--];
        }
        return ans;
    }
};
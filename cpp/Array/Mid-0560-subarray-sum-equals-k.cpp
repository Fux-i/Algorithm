#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        vector<int> pres(n + 1);
        for (int i = 0; i < n; i++) {
            pres[i + 1] = pres[i] + nums[i];
        }

        unordered_map<int, int> map;
        for (int num : pres) {
            if (map.contains(num - k)) {
                ans += map[num - k];
            }
            map[num]++;
        }
        return ans;
    }
};
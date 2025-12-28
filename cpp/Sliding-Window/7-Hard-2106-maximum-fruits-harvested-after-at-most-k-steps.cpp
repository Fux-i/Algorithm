#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int> > &fruits, int startPos, int k) {
        // most left
        int left = ranges::lower_bound(fruits, startPos - k, {}, [](auto &f) { return f[0]; }) - fruits.begin();

        int ans = 0, s = 0, n = fruits.size();
        // most right
        for (int right = left; right < n && fruits[right][0] <= startPos + k; right++) {
            s += fruits[right][1];
            while (fruits[right][0] * 2 - fruits[left][0] - startPos > k &&
                   fruits[right][0] - fruits[left][0] * 2 + startPos > k) {
                s -= fruits[left][1];
                left++;
            }
            ans = max(ans, s);
        }
        return ans;
    }
};

#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        stack<int> s{};
        for (int i = 0; i < n; ++i) {
            int h = height[i];
            // find the most left pos of the shorters
            if (!s.empty()) {
                int last = s.top(), last_height = height[last];
                while (h >= last_height) {
                    s.pop();
                    if (s.empty()) break;
                    last = s.top();
                    last_height = height[last];
                }
                // if there is shorter
                if (last != -1) {
                    for (int j = last + 1; j < i; ++j) {
                        ans += min(h, last_height) - height[j];
                        height[j] = h;
                    }
                }
            }
            s.push(i);
        }
        return ans;
    }
};
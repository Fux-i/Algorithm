#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_size = 0;
        vector<pair<int, int>> v{}; // index, height

        for (int i = 0; i < n; ++i) {
            int h = heights[i];
            if (i > 0 && h == heights[i - 1] && i < n - 1 && h == heights[i + 1]) continue;
            // 为0
            if (h == 0) {
                while (!v.empty())
                    v.pop_back();
                continue;
            }
            //
            pair<int, int> temp = {-1, -1};
            while (!v.empty() && v.back().second > h) {
                temp = v.back();
                v.pop_back();
            }
            if (temp.first == -1) v.emplace_back(i, h);
            else if (v.empty() || v.back().second < h) {
                v.emplace_back(temp.first, h);
            }
            // calculate height
            for (auto &[index, height] : v) {
                max_size = max(max_size, height * (i - index + 1));
            }
        }

        return max_size;
    }
};
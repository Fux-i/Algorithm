#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans{};
        ans.reserve(numRows);
        ans.push_back({1});
        for (int i = 2; i <= numRows; ++i) {
            vector<int> newOne{1};
            newOne.reserve(i);
            for (int j = 2; j < i; ++j) {
                newOne.emplace_back(ans[i - 2][j - 2] + ans[i - 2][j - 1]);
            }
            newOne.emplace_back(1);
            ans.push_back(newOne);
        }
        return ans;
    }
};

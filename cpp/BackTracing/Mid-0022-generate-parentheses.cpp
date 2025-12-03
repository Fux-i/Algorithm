#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int l = 0;
        int r = 0;
        string one;
        vector<string> ans;

        auto dfs = [&](this auto&& dfs) -> void {
            if (r == n) {
                ans.push_back(one);
                return;
            }
            if (l < n) {
                l++;
                one.push_back('(');
                dfs();
                one.pop_back();
                l--;
            }
            if (r < l) {
                r++;
                one.push_back(')');
                dfs();
                one.pop_back();
                r--;
            }
        };

        dfs();
        return ans;
    }
};
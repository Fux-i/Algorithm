#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), len = 1, start = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int offset = 0; offset < n; ++offset) {
            for (int pos = 0; pos + offset < n; ++pos) {
                dp[pos][pos + offset] = offset < 2
                    ? s[pos] == s[pos + offset]
                    : dp[pos + 1][pos + offset - 1] && s[pos] == s[pos + offset];
                if (dp[pos][pos + offset] && offset >= len) {
                    start = pos;
                    len = offset + 1;
                }
            }
        }
        return s.substr(start, len);
    }
};
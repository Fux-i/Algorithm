#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> m;
        for (char c : t) {
            m[c]--;
        }
        int n = s.size(), incomplete = m.size();
        int l = 0, r = 0;

        int minLen = INT_MAX;
        string ans = "";

        while (r < n) {
            if (!m.contains(s[r])) {
                r++;
                continue;
            }
            // contain s[r]
            if (++m[s[r]] == 0)
                incomplete--;

            if (incomplete == 0) {
                while (l < r) {
                    if (m.contains(s[l])) {
                        if (m[s[l]] == 0) break;
                        m[s[l]]--;
                    }
                    l++;
                }
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    ans = s.substr(l, r - l + 1);
                }
            }
            r++;
        }
        return ans;
    }
};
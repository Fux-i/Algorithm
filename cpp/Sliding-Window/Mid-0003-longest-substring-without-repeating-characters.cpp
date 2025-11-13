#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        int l = 0, r = 0;
        int result = 0;
        while (r < n) {
            char c = s[r];
            if (m.contains(c)) {
                int pos = m[c];
                while (l <= pos) {
                    m.erase(s[l]);
                    l++;
                }
            } else {
                result = max(result, r - l + 1);
            }
            m[c] = r;
            r++;
        }
        return result;
    }
};

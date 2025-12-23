#include <string>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(), l = 0, r = -1, ans = 0, num = 0;
        auto check = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        while (r < n - 1) {
            if (check(s[++r])) ++num;
            if (r >= k) {
                if (check(s[l++])) --num;
            }
            ans = max(ans, num);
        }
        return ans;
    }
};

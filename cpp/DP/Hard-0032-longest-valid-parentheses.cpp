#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) maxlength = max(maxlength, 2 * right);
            else if (right > left) left = right = 0;
        }
        left = right = 0;
        for (int i = (int) s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) maxlength = max(maxlength, 2 * left);
            else if (left > right) left = right = 0;
        }
        return maxlength;
    }
};

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int ans = 0;
        for (short i = 0; i < n - 1; ++i) {
            int match = 0;
            for (short j = i; j < n; ++j) {
                if (s[j] == '(') ++match;
                else --match;
                if (match == 0) ans = max(ans, j - i + 1);
                else if (match < 0 || match > n / 2 + 1) break;
            }
        }
        return ans;
    }
};*/
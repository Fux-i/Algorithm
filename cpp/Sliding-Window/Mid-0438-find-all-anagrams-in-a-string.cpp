#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size(), np = p.size();
        vector<int> res;
        if (ns < np) return res;

        int freq[26] = {0};
        for (char c: p) freq[c - 'a']--;

        int matchCnt = 0;
        for (int i : freq)
            if (i == 0) ++matchCnt;

        int l = 0;
        for (int r = 0; r < ns; ++r) {
            int idx = s[r] - 'a';
            if (++freq[idx] == 0) matchCnt++;
            else if (freq[idx] == 1) matchCnt--;

            if (r - l + 1 > np) {
                idx = s[l++] - 'a';
                if (--freq[idx] == 0) matchCnt++;
                else if (freq[idx] == -1) matchCnt--;
            }

            if (matchCnt == 26) res.push_back(l);
        }
        return res;
    }
};

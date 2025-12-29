#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ranges::sort(potions);
        int n = spells.size();
        vector<int> ans{};
        ans.reserve(n);
        for (int i = 0; i < n; i++) {
            double target = (double)success / spells[i];
            int j = potions.end() - ranges::lower_bound(potions, target);
            ans.push_back(j);
        }
        return ans;
    }
};
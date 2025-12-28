#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int ans = 0, n = arrivals.size();
        unordered_map<int, int> table{};
        for (int i = 0; i < n; ++i) {
            if (i >= w) table[arrivals[i - w]] = table[arrivals[i - w]] == 0 ? 0 : table[arrivals[i - w]] - 1;
            if (table[arrivals[i]] == m) {
                ++ans;
                arrivals[i] = 0;
            }
            else table[arrivals[i]]++;
        }
        return ans;
    }
};
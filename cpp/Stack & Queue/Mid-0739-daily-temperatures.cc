#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct MyComp {
    bool operator()(pair<int, int>& a, pair<int, int>&b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> v(n,0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComp> pq{};

        for (int i = 0; i < n; ++i) {
            int cur = temp[i];
            while (!pq.empty()) {
                auto [val, idx] = pq.top();
                if (val < cur) {
                    v[idx] = i - idx;
                    pq.pop();
                } else break;
            }
            if (i == n - 1) break;
            if (cur < temp[i + 1]) v[i] = 1;
            else pq.emplace(cur, i);
        }

        return v;
    }
};
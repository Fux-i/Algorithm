#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> > &a) {
        const int n = a.size(), m = a[0].size();
        vector<vector<bool> > vis(n, vector<bool>(m));
        auto dfs = [&](auto &self, int i, int j) {
            if (i < 0 || i > n - 1 || j < 0 || j > m - 1 || a[i][j] == '0' || vis[i][j]) {
                return;
            }
            vis[i][j] = true;
            array<array<int, 2>, 4> d{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
            for (auto [dx, dy]: d) {
                self(self, i + dx, j + dy);
            }
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && a[i][j] == '1') {
                    dfs(dfs, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

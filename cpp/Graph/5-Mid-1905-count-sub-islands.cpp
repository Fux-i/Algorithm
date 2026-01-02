#include <vector>
using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int> > &grid1, vector<vector<int> > &grid2) {
        int m = grid1.size(), n = grid1[0].size();
        auto dfs = [&](this auto &&dfs, int i, int j)-> bool {
            if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0)return true;
            if (grid1[i][j] == 0)return false;
            grid2[i][j] = 0;
            bool target = true;
            target &= dfs(i, j + 1);
            target &= dfs(i, j - 1);
            target &= dfs(i + 1, j);
            target &= dfs(i - 1, j);
            return target;
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1)ans += dfs(i, j);
            }
        }
        return ans;
    }
};

#include <queue>
#include <vector>
using namespace std;

class Solution {
    static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    vector<vector<int> > updateMatrix(vector<vector<int> > &mat) {
        queue<pair<int, int> > q{};
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    visited[i][j] = true;
                    for (auto &dir: dirs) {
                        int ii = i + dir[0];
                        int jj = j + dir[1];
                        if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                        q.emplace(ii, jj);
                    }
                }
            }
        }
        int dis = 1;
        while (!q.empty()) {
            const int size = q.size();
            for (int k = 0; k < size; ++k) {
                auto [i, j] = q.front();
                q.pop();
                if (visited[i][j]) continue;
                visited[i][j] = true;
                mat[i][j] = dis;
                for (auto &dir: dirs) {
                    int ii = i + dir[0];
                    int jj = j + dir[1];
                    if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                    q.emplace(ii, jj);
                }
            }
            ++dis;
        }
        return mat;
    }
};

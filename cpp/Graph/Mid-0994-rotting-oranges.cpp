#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int> > &grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        queue<pair<int, int> > qu{};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int type = grid[i][j];
                if (type == 1) count++;
                else if (type == 2) qu.push({i, j});
            }
        }

        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto rotAround = [&](int row, int col) {
            for (auto &dir: directions) {
                int i = row + dir[0], j = col + dir[1];
                if (i < 0 || j < 0 || i >= n || j >= m) continue;
                if (grid[i][j] == 1) {
                    grid[i][j] = 2;
                    qu.push({i, j});
                    count--;
                }
            }
        };

        int round = 0, lastCount = count;
        while (count > 0) {
            int rotNum = qu.size();
            while (rotNum--) {
                auto [row, col] = qu.front();
                qu.pop();
                rotAround(row, col);
            }
            if (lastCount == count) return -1;
            round++;
            lastCount = count;
        }

        return round;
    }
};

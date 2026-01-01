#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        char& c = board[click[0]][click[1]];
        if (c == 'M') {
            c = 'X';
            return board;
        }
        int n = board.size(), m = board[0].size();

        auto countBomb = [&](int i, int j) {
            int bomb = 0;
            for (int a = -1; a < 2; ++a) {
                int row = i + a;
                for (int b = -1; b < 2; ++b) {
                    int col = j + b;
                    if (row < 0 || col < 0 || row >= n || col >= m || (a == 0 && b == 0)) continue;
                    if (board[row][col] == 'M') {
                        bomb++;
                    }
                }
            }

            return bomb;
        };

        vector<vector<bool>> visited(n, vector<bool>(m));
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j]) return;

            int bomb = countBomb(i, j);
            if (bomb == 0) {
                board[i][j] = 'B';
                visited[i][j] = true;

                for (int a = -1; a < 2; ++a) {
                    int row = i + a;
                    for (int b = -1; b < 2; ++b) {
                        int col = j + b;
                        if (row < 0 || col < 0 || row >= n || col >= m || (a == 0 && b == 0)) continue;
                        dfs(row, col);
                    }
                }
            } else {
                board[i][j] = bomb + '0';
                visited[i][j] = true;
            }

        };

        dfs(click[0], click[1]);
        return board;
    }
};
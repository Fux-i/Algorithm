#include <bitset>
#include <string>
#include <variant>
#include <vector>
using namespace std;

class Solution {
    bool success = false;
    vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        visited.assign(n, vector<bool>(m, false));

        /*
        // 优化一
        unordered_map<char, int> word_cnt;
        for (char c : word) {
            if (++word_cnt[c] > cnt[c]) {
                return false;
            }
        }

        // 优化二
        if (cnt[word.back()] < cnt[word[0]]) {
            ranges::reverse(word);
        }

        作者：灵茶山艾府
        链接：https://leetcode.cn/problems/word-search/solutions/2927294/liang-ge-you-hua-rang-dai-ma-ji-bai-jie-g3mmm/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        */

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                dfs(board, word, 0, i, j);
        }

        return success;
    }

    void dfs(vector<vector<char>>& board, string& word, int idx, int row, int col) {
        if (success) return;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return;
        if (visited[row][col] || word[idx] != board[row][col]) return;
        if (idx == word.size() - 1) {
            success = true;
            return;
        }
        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto& dir : directions) {
            visited[row][col] = true;
            dfs(board, word, idx + 1, row + dir[0], col + dir[1]);
            visited[row][col] = false;
        }
    }
};
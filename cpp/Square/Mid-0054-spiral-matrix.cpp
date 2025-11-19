#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int y = 0, x = -1;

        vector<int> res;
        res.reserve(n * m);

        while (m > 0 && n > 0) {
            for (int j = 0; j < n; j++) {
                x++;
                res.push_back(matrix[y][x]);
            }
            if (--m == 0) break;
            for (int i = 0; i < m; i++) {
                y++;
                res.push_back(matrix[y][x]);
            }
            if (--n == 0) break;
            for (int j = 0; j < n; j++) {
                x--;
                res.push_back(matrix[y][x]);
            }
            if (--m == 0) break;
            for (int i = 0; i < m; i++) {
                y--;
                res.push_back(matrix[y][x]);
            }
            if (--n == 0) break;
        }
        return res;
    }
};
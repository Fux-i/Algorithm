#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int ni = n / 2, nj = (n + 1) / 2;
        for (int i = 0; i < ni; i++) {
            for (int j = 0; j < nj; j++) {
                int temp = matrix[i][j];
                swap(temp, matrix[j][n - 1 - i]);
                swap(temp, matrix[n - 1 - i][n - 1 - j]);
                swap(temp, matrix[n - 1 - j][i]);
                swap(temp, matrix[i][j]);
            }
        }
    }
};

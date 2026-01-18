#include <vector>
using namespace std;

class Solution {
public:
	int largestMagicSquare(vector<vector<int> > &grid) {
		int m = grid.size(), n = grid[0].size();
		// 每一行的前缀和
		vector<vector<int> > row_sum(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			row_sum[i][0] = grid[i][0];
			for (int j = 1; j < n; ++j) {
				row_sum[i][j] = row_sum[i][j - 1] + grid[i][j];
			}
		}
		vector<vector<int> > col_sum(m, vector<int>(n));
		for (int j = 0; j < n; ++j) {
			col_sum[0][j] = grid[0][j];
			for (int i = 1; i < m; ++i) {
				col_sum[i][j] = col_sum[i - 1][j] + grid[i][j];
			}
		}

		for (int edge = min(m, n); edge >= 2; --edge) {
			for (int i = 0; i + edge <= m; ++i) {
				for (int j = 0; j + edge <= n; ++j) {
					int stdsum = row_sum[i][j + edge - 1] - (j ? row_sum[i][j - 1] : 0);
					bool check = true;
					for (int ii = i + 1; ii < i + edge; ++ii) {
						if (row_sum[ii][j + edge - 1] - (j ? row_sum[ii][j - 1] : 0) != stdsum) {
							check = false;
							break;
						}
					}
					if (!check) continue;
					for (int jj = j; jj < j + edge; ++jj) {
						if (col_sum[i + edge - 1][jj] - (i ? col_sum[i - 1][jj] : 0) != stdsum) {
							check = false;
							break;
						}
					}
					if (!check) continue;
					int d1 = 0, d2 = 0;
					for (int k = 0; k < edge; ++k) {
						d1 += grid[i + k][j + k];
						d2 += grid[i + k][j + edge - 1 - k];
					}
					if (d1 == stdsum && d2 == stdsum) {
						return edge;
					}
				}
			}
		}

		return 1;
	}
};

#include <vector>
using namespace std;

class Solution {
public:
	int getRect(const vector<vector<int> > &P, int x1, int y1, int x2, int y2) {
		return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
	}

	int maxSideLength(vector<vector<int> > &mat, int threshold) {
		int m = mat.size(), n = mat[0].size();
		vector<vector<int> > P(m + 1, vector<int>(n + 1));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
			}
		}

		int r = min(m, n), ans = 0;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int c = ans + 1; c <= r; ++c) {
					if (i + c - 1 <= m && j + c - 1 <= n && getRect(P, i, j, i + c - 1, j + c - 1) <= threshold) {
						++ans;
					} else {
						break;
					}
				}
			}
		}
		return ans;
	}
};

/*
class Solution {
public:
	int maxSideLength(vector<vector<int> > &mat, int threshold) {
		int n = mat.size(), m = mat[0].size();

		vector<vector<int> > pre_sum = mat;
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				pre_sum[i][j] += pre_sum[i][j - 1];
			}
		}

		int k = min(n, m);
		while (k > 0) {
			for (int i = 0; i <= n - k; ++i) {
				for (int j = k - 1; j < m; ++j) {
					int sum = 0;
					for (int t = i; t < i + k; ++t) {
						sum += pre_sum[t][j] - (j == k - 1 ? 0 : pre_sum[t][j - k]);
						if (sum > threshold) break;
					}
					if (sum <= threshold)
						return k;

				}
			}
			--k;
		}

		return 0;
	}
};*/

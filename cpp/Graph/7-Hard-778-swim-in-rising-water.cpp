#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	int find(vector<int> &f, int x) {
		if (f[x] == x) {
			return x;
		}
		int fa = find(f, f[x]);
		f[x] = fa;
		return fa;
	}

	void merge(vector<int> &f, int x, int y) {
		int fx = find(f, x), fy = find(f, y);
		f[fx] = fy;
	}

	int swimInWater(vector<vector<int> > &grid) {
		int n = grid.size();
		vector<int> f(n * n);
		for (int i = 0; i < n * n; i++) {
			f[i] = i;
		}

		vector<pair<int, int> > idx(n * n); // 存储每个平台高度对应的位置
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				idx[grid[i][j]] = make_pair(i, j);
			}
		}

		vector<pair<int, int> > directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		for (int threshold = 0; threshold < n * n; threshold++) {
			auto [i, j] = idx[threshold];
			for (const auto [di, dj]: directions) {
				int ni = i + di, nj = j + dj;
				if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] <= threshold) {
					merge(f, i * n + j, ni * n + nj);
				}
			}
			if (find(f, 0) == find(f, n * n - 1)) {
				return threshold;
			}
		}
		return -1; // cannot happen
	}
};

/*class Solution {
	static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
	int swimInWater(vector<vector<int>> &grid) {
		int n = grid.size();
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		queue<pair<int, int>> q{};
		queue<pair<int, int>> q_next{};

		q.emplace(0, 0);
		bool reached = false;
		int t = 0;

		auto dfs = [&](this auto&& dfs, int i, int j) {
			if (reached) return;
			if (i == n - 1 && j == n - 1) {
				reached = true;
				return;
			}
			visited[i][j] = true;
			for (auto& dir : dirs) {
				int i1 = i + dir[0];
				int j1 = j + dir[1];
				if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= n || visited[i1][j1])
					continue;

				if (t < grid[i1][j1])
					q_next.emplace(i1, j1);  // 放入下一轮队列
				else
					dfs(i1, j1);
			}
		};

		while (!q.empty() && !reached) {
			int size = q.size();
			for (int k = 0; k < size; ++k) {
				auto [i, j] = q.front(); q.pop();
				if (visited[i][j]) continue;

				if (t < grid[i][j]) {
					q_next.emplace(i, j);
					continue;
				}
				dfs(i, j);
			}
			swap(q, q_next);
			q_next = queue<pair<int, int>>();

			++t;
		}

		return reached ? t - 1 : -1;
	}
};*/

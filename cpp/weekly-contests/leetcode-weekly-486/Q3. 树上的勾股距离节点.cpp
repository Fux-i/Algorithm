#include <vector>
#include <queue>
#include <algorithm>
#include <array>
using namespace std;

class Solution {
public:
	vector<int> bfs(int n, const vector<vector<int> > &graph, int start) {
		vector<int> dist(n, -1);
		queue<int> q;

		dist[start] = 0;
		q.push(start);

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v: graph[u]) {
				if (dist[v] == -1) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}

		return dist;
	}

	int specialNodes(int n, vector<vector<int> > &edges, int x, int y, int z) {
		vector<vector<int> > graph(n);
		for (const auto &e: edges) {
			graph[e[0]].push_back(e[1]);
			graph[e[1]].push_back(e[0]);
		}

		vector<int> dist_x = bfs(n, graph, x);
		vector<int> dist_y = bfs(n, graph, y);
		vector<int> dist_z = bfs(n, graph, z);

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			array<int, 3> d = {dist_x[i], dist_y[i], dist_z[i]};
			ranges::sort(d);

			long long a = d[0], b = d[1], c = d[2];
			if (a * a + b * b == c * c) {
				++ans;
			}
		}

		return ans;
	}
};

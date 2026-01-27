#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	int minCost(int n, vector<vector<int> > &edges) {
		vector<vector<pair<int, int> > > graph(n);
		for (auto &e: edges) {
			graph[e[0]].emplace_back(e[1], e[2]);
			graph[e[1]].emplace_back(e[0], 2 * e[2]);
		}

		vector<int> dist(n, INT_MAX);
		dist[0] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
		pq.emplace(0, 0);

		while (!pq.empty()) {
			auto [d, u] = pq.top();
			pq.pop();
			if (d != dist[u]) continue;
			if (u == n - 1) return d;
			for (auto [v, w]: graph[u]) {
				if (dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pq.emplace(dist[v], v);
				}
			}
		}
		return -1;
	}
};

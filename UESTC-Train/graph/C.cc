#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pi = pair<int, int>;

constexpr int maxn = 4e5 + 2;
int n, x;
ll dis[maxn];
bool vis[maxn];
vector<pi> g[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		g[i].push_back({1, (i + v) % n + n});
		g[i + n].push_back({0, i});
		g[i + n].push_back({1, (i + 1) % n + n});
	}
	n *= 2;
	for (int i = 0; i < n; ++i) dis[i] = LLONG_MAX >> 1;
	priority_queue<pll, vector<pll>, greater<>> q{};
	q.emplace(0, 0);
	while (!q.empty()) {
		auto [d, u] = q.top(); q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto [w, v]: g[u]) {
			ll dd = d + w;
			if (dd < dis[v]) {
				dis[v] = dd;
				q.emplace(dd, v);
			}
		}
	}
	cout << dis[x];
}

/*
11 5
6 0 0 0 0 0 0 0 0 0 5

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pi = pair<int, int>;

constexpr int maxn = 2e5 + 2, maxm = 4e5 + 2;
int n, m, hd[maxn], to[maxm], nxt[maxm], in[maxn], out[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		to[i] = v;
		nxt[i] = hd[u];
		hd[u] = i;
		++in[v], ++out[u];
	}
	for (int i = 1; i <= n; ++i) {
		if (in[i] != out[i] || in[i] == 0) {
			cout << -1;
			return 0;
		}
	}

	vector<int> stk, path;
	stk.reserve(m + 1);
	path.reserve(m + 1);
	stk.push_back(1);
	while (!stk.empty()) {
		int u = stk.back();
		if (int e = hd[u]) {
			hd[u] = nxt[e];
			stk.push_back(to[e]);
		} else {
			path.push_back(u);
			stk.pop_back();
		}
	}

	int len = path.size();
	if (len != m + 1) {
		cout << -1;
		return 0;
	}
	for (int i = len - 1; i >= 0; --i)
		cout << path[i] << " \n"[i == 0];
}

/*
4 5
1 2
2 3
3 1
1 4
4 1

6 10
1 2
2 3
3 4
4 5
5 3
3 6
6 1
3 7
7 4
4 3

4 6
1 2
2 1
2 3
3 2
2 4
4 2

*/

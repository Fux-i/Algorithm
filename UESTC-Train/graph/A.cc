#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using node = pair<ll, int>;

constexpr int maxn = 1e5 + 2, maxm = 5e5 + 2;
int n, m, s, nxt[maxm], head[maxn], c = 0;
ll dis[maxn];
struct edge {
  int v, w;
} e[maxm];
bool vis[maxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> s;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    e[++c] = {v, w};
    nxt[c] = head[u];
    head[u] = c;
  }
  for (int i = 1; i <= n; ++i)
    dis[i] = LLONG_MAX >> 1;
  dis[s] = 0;
  priority_queue<node, vector<node>, greater<>> q{};
  q.emplace(0, s);
  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (vis[u])
      continue;
    vis[u] = true;
    for (int i = head[u]; i; i = nxt[i]) {
      auto [v, w] = e[i];
      ll dd = dis[u] + w;
      if (dis[v] > dd) {
        dis[v] = dd;
        q.emplace(dd, v);
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    cout << dis[i] << " \n"[i == n];
}

/*
6 7 1
1 2 5
1 3 6
2 4 10
3 4 4
3 5 2
4 6 3
5 6 1


*/

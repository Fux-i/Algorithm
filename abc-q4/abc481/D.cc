#include <iostream>
#include <limits>
#include <queue>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
constexpr int maxn = 2e5 + 2;
int n, m, s, t;
int h[maxn], to[maxn], nxt[maxn], cost[maxn];
ll dis[maxn];
bool fix[maxn];
priority_queue<pll, vector<pll>, greater<>> q;

void solve() {
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    nxt[i] = h[u];
    to[i] = v;
    h[u] = i;
    cost[i] = 1;
  }
  for (int u = 1; u <= n; u++) {
    dis[u] = numeric_limits<ll>::max();
    int e_to_min = 0, v_min = n + 1;
    for (int e = h[u]; e; e = nxt[e]) {
      int v = to[e];
      if (v < v_min) {
        v_min = v;
        e_to_min = e;
      }
    }
    cost[e_to_min] = 0;
  }
  q.emplace(0, s);
  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (u == t) {
      cout << d;
      return;
    }
    if (fix[u])
      continue;
    fix[u] = true;
    for (int e = h[u]; e; e = nxt[e]) {
      int v = to[e];
      if (fix[v])
        continue;
      ll nd = d + cost[e];
      dis[v] = min(dis[v], nd);
      q.emplace(dis[v], v);
    }
  }

  cout << -1 << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

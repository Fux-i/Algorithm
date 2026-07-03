#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
using pii = struct {
  ll d;
  int u;
};
constexpr int maxn = 2e5 + 5;
constexpr int maxm = maxn * 4;
int n, m, y;
bool visited[maxn];
int h[maxn], e[maxm], to[maxm], w[maxm], cnt;
ll d[maxn];
struct comp {
  bool operator()(pii &a, pii &b) { return a.d > b.d; }
};
priority_queue<pii, vector<pii>, comp> q;

void add(int u, int v, int o) {
  to[++cnt] = v;
  w[cnt] = o;
  e[cnt] = h[u];
  h[u] = cnt;
}

void uadd(int u, int v, int o) {
  add(u, v, o);
  add(v, u, o);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> m >> y;
  uadd(n + 1, n + 2, y);
  for (int i = 1; i <= m; ++i) {
    int u, v, t;
    cin >> u >> v >> t;
    uadd(u, v, t);
  }
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    add(i, n + 1, x);
    add(n + 2, i, x);
  }
  for (int i = 2; i <= n + 2; ++i)
    d[i] = LLONG_MAX / 2;
  d[1] = 0;
  q.emplace(0, 1);
  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();
    if (visited[u])
      continue;
    visited[u] = true;
    for (int i = h[u]; i; i = e[i]) {
      int v = to[i], t = w[i];
      if (d[v] > du + t) {
        d[v] = du + t;
        q.emplace(d[v], v);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    cout << d[i] << ' ';
  }
}

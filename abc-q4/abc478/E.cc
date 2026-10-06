// -graph -tarjan
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
constexpr int maxn = 2e5 + 2;
int n, q;
int nxt[maxn], to[maxn], h[maxn], t[maxn], idx = 1;
int dfn[maxn], low[maxn], dfn_i = 1;
int stk[maxn], tp = 0;
bool in_stk[maxn];
int scc[maxn], scc_i = 0;
bool ok = true;
vector<int> vec[maxn];
int f[maxn];

void give() {
  int best = 0;
  for (int u : vec[scc_i]) {
    for (int i = h[u]; i; i = nxt[i]) {
      int v = to[i];
      if (scc[v] == scc_i && t[i]) {
        ok = false;
        return;
      } else {
        best = max(best, t[i] + f[v]);
      }
    }
  }
  for (int u : vec[scc_i])
    f[u] = best;
}

void tarjan(int u) {
  dfn[u] = low[u] = dfn_i++, stk[tp++] = u, in_stk[u] = true;

  for (int i = h[u]; i; i = nxt[i]) {
    int v = to[i];
    if (dfn[v] == 0) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stk[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }

  if (low[u] == dfn[u]) {
    scc_i++;
    int x;
    do {
      x = stk[--tp];
      in_stk[x] = false;
      scc[x] = scc_i;
      vec[scc_i].push_back(x);
    } while (x != u);

    give();
  }
}

void add(int ti, int u, int v) {
  nxt[idx] = h[u];
  to[idx] = v;
  t[idx] = ti;
  h[u] = idx++;
}

void solve() {
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    int ti, ui, vi;
    cin >> ti >> ui >> vi;
    add(ti, ui, vi);
  }

  for (int i = 1; i <= n; i++)
    if (dfn[i] == 0)
      tarjan(i);

  if (!ok) {
    cout << "No\n";
    return;
  }

  int mx = 0;
  for (int i = 1; i <= n; i++)
    mx = max(mx, f[i]);
  mx++;

  cout << "Yes\n";
  for (int i = 1; i <= n; i++)
    cout << mx - f[i] << " \n"[i == n];
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

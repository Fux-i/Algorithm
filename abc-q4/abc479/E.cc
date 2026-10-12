// -tree -subtree -dfn -diff

#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 2e5 + 2, maxm = 4e5 + 2;
int n, a[maxn], b[maxn];
int nxt[maxm], to[maxm], h[maxn], idx = 0;
int siz[maxn], pa[maxn], tin[maxn], tout[maxn], ord[maxn], timer = 0;
int stk[maxn], top = 0;
bool vis[maxn];

ll diff[maxn], ans[maxn];

void add(int u, int v) {
  to[++idx] = v;
  nxt[idx] = h[u];
  h[u] = idx;
}

void solve() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a[i] >> b[i];
    add(a[i], b[i]);
    add(b[i], a[i]);
  }
  for (int i = 1; i <= n; i++)
    siz[i] = 1;
  stk[++top] = 1, vis[1] = true, tin[1] = ++timer, ord[timer] = 1;
  while (top) {
    int u = stk[top], e = h[u], v = to[e];
    if (e) {
      h[u] = nxt[e];
      if (vis[v])
        continue;
      vis[v] = true, stk[++top] = v, pa[v] = u, tin[v] = ++timer,
      ord[timer] = v;
    } else {
      --top;
      tout[u] = timer;
      if (pa[u])
        siz[pa[u]] += siz[u];
    }
  }

  ll base = 0;
  for (int i = 1; i < n; i++) {
    int c = pa[a[i]] == b[i] ? a[i] : b[i];
    if (siz[c] * 2LL > n) {
      diff[tin[c]] += i;
      diff[tout[c] + 1] -= i;
    } else {
      base += i;
      diff[tin[c]] -= i;
      diff[tout[c] + 1] += i;
    }
  }

  for (int i = 1; i <= n; i++) {
    base += diff[i];
    ans[ord[i]] = base;
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " \n"[i == n];
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

// https://www.luogu.com.cn/problem/P1352
// tag: -dp -tree

#include <iostream>

using namespace std;
using ll = long long;
constexpr int maxn = 6e3 + 2;
int r[maxn];
int nxt[maxn], to[maxn], h[maxn];
int root;
bool is_child[maxn];
int dp[maxn][2];
int n, m;

void dfs(int u) {
  dp[u][0] = 0;
  dp[u][1] = r[u];
  for (int i = h[u]; i; i = nxt[i]) {
    int v = to[i];
    dfs(v);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> r[i];
  for (int i = 1; i < n; ++i) {
    int l, k;
    cin >> l >> k;
    nxt[i] = h[k];
    to[i] = l;
    h[k] = i;
    is_child[l] = true;
  }
  for (int i = 1; i <= n; ++i) {
    if (!is_child[i]) {
      root = i;
      break;
    }
  }
  dfs(root);
  cout << max(dp[root][0], dp[root][1]);
}

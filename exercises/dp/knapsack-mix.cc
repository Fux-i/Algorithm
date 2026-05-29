// https://www.luogu.com.cn/problem/P1833
// tag: -knapsack -mixture

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxn = 7e5 + 2, maxt = 1e3 + 2;
int h1, m1, h2, m2, n, m, t[maxn], c[maxn], p[maxn];
ll dp[maxt];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &n);
  m = (h2 - h1) * 60 + m2 - m1;
  int idx = 1;
  for (int i = 1; i <= n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    if (z == 0) {
      t[idx] = x, c[idx] = y, p[idx] = 0, idx++;
      continue;
    }
    int a = 1;
    while (z > a) {
      z -= a;
      t[idx] = x * a, c[idx] = y * a, p[idx] = 1, idx++;
      a <<= 1;
    }
    t[idx] = x * z, c[idx] = y * z, p[idx] = 1, idx++;
  }
  for (int i = 1; i < idx; ++i) {
    if (p[i] == 1) {
      for (int j = m; j >= t[i]; --j) {
        dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
      }
    } else {
      for (int j = t[i]; j <= m; ++j) {
        dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
      }
    }
  }
  printf("%lld", dp[m]);
}

// https://www.luogu.com.cn/problem/P1616
// tag: -knapsack -complete

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxt = 1e7 + 2, maxm = 1e4 + 2;
ll t, m, a[maxm], b[maxm], dp[maxt];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> t >> m;
  for (int i = 1; i <= m; ++i)
    cin >> a[i] >> b[i];
  for (int i = 1; i <= m; ++i)
    for (int j = a[i]; j <= t; ++j)
      dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
  cout << dp[t];
}

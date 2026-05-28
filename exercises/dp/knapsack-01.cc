// https://www.luogu.com.cn/problem/P2871
// tag: -knapsack -01

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxn = 3405, maxm = 12888;
int n, m, w[maxn], d[maxn], dp[maxm];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> w[i] >> d[i];
  for (int i = 1; i <= n; ++i)
    for (int j = m; j >= w[i]; --j)
      dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
  cout << dp[m];
}

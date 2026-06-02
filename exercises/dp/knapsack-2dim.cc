// https://www.luogu.com.cn/problem/P1855
// tag: -knapsack -2dim

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxn = 102, maxm = 202, maxt = 202;
int n, M, T, m[maxm], t[maxt], dp[maxm][maxt];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> M >> T;
  for (int i = 1; i <= n; ++i)
    cin >> m[i] >> t[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = M; j >= m[i]; --j) {
      for (int k = T; k >= t[i]; --k) {
        dp[j][k] = max(dp[j][k], dp[j - m[i]][k - t[i]] + 1);
      }
    }
  }
  cout << dp[M][T];
}

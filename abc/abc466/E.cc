// -dp

#include <iostream>

using namespace std;
using ll = long long;
using pii = struct {
  int a, b;
};
constexpr int maxn = 2e5 + 2, maxk = 21;
int n, k;
ll a[maxn], b[maxn];
ll dp[maxn][maxk];

void solve() {
  cin >> n >> k;
  k = 2 * k + 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    dp[i][0] = dp[i - 1][0] + a[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < k && j <= i + 1; ++j) {
      dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + (j & 1 ? b[i] : a[i]);
    }
  }
  ll ans = 0;
  for (int i = 0; i < k; ++i)
    ans = max(ans, dp[n][i]);
  cout << ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

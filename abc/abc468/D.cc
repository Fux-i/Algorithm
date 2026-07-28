#include <iostream>
#include <string>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 1e4 + 2;
int n, m, dp[maxn][maxn];

void solve() {
  string s;
  cin >> s;
  int siz = s.size();
  for (int i = 0; i < siz - 1; i++) {
    dp[i][i + 1] = s[i] == s[i + 1] ? 0 : 1;
  }
  int ans = siz + siz - 1;
  for (int d = 2; d < siz; d++) {
    for (int i = 0; i + d < siz; i++) {
      int j = i + d;
      dp[i][j] = dp[i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);
      if (dp[i][j] < 2) {
        ans++;
      }
    }
  }
  // for (int i = 0; i < siz; ++i) {
  //   for (int j = 0; j < siz; ++j) {
  //     if (j < i)
  //       cout << '*';
  //     else
  //       cout << dp[i][j];
  //   }
  //   cout << '\n';
  // }
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

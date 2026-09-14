#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;
constexpr int maxn = 1e4;
int n, s, ans = 0;
ll L, pre[maxn], a[maxn];

ll get_len(int l, int r) { return pre[r] - pre[l]; }

void solve() {
  cin >> n >> s >> L;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i - 1];
  }
  pre[n] = pre[n - 1] + a[n - 1];
  for (int i = 1; i <= s; i++) {
    for (int j = s; j <= n; j++) {
      ll len = get_len(i, j);
      ll len1 = len + get_len(i, s);
      ll len2 = len + get_len(s, j);
      if (len1 > L && len2 > L)
        continue;
      ans = max(ans, j - i + 1);
    }
  }
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

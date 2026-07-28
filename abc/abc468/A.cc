#include <iostream>

using namespace std;
constexpr int maxn = 102;
int n, a[maxn];

void solve() {
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (i > 2) {
      if (a[i - 2] < a[i - 1] && a[i - 1] > a[i]) {
        ans++;
      }
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

#include <iostream>

using namespace std;
using ll = long long;
constexpr int maxn = 22;
ll n, w, a[maxn], b[maxn];
ll di = 0, vo = 0, ans = 0;

void calc(int i) {
  if (vo > w || i > n + 1) {
    return;
  } else {
    ans = max(ans, di);
    if (i == n + 1)
      return;
  }
  calc(i + 1);
  vo += b[i];
  di += a[i];
  calc(i + 1);
  di -= a[i];
  vo -= b[i];
}

void solve() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i];
  calc(1);
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

#include <algorithm>
#include <iostream>

using namespace std;
constexpr int maxn = 2e5 + 2;
int n, k, t;
int a[maxn];

void solve() {
  cin >> n >> k >> t;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  int time = 0, i = 1, cnt = 0;
  while (time < t) {
    while (i <= n && a[i] <= time) {
      time = a[i] + k;
      ++i;
    }
    if (time >= t)
      break;
    time += k;
    cnt++;
  }
  if (time < t) {
    cnt += (t - time) / k + 1;
  }
  cout << cnt << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

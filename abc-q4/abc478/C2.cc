#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

constexpr int maxn = 2e5 + 5;
int n, k, a[maxn], mn[maxn], mx[maxn];
bool l[maxn], r[maxn];

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  l[0] = l[1] = true;
  for (int i = 2; i <= n - k; i++) {
    if (a[i] < a[i - 1])
      break;
    l[i] = true;
  }
  r[n] = r[n + 1] = true;
  for (int i = n - 1; i > k; i--) {
    if (a[i] > a[i + 1])
      break;
    r[i] = true;
  }
  int mxv = mx[0] = 0;
  for (int i = 1; i <= n; i++) {
    mxv = max(mxv, a[i]);
    mx[i] = mxv;
  }
  int mnv = mn[n + 1] = INT_MAX;
  for (int i = n; i > 0; i--) {
    mnv = min(mnv, a[i]);
    mn[i] = mnv;
  }
  bool possible = false;
  for (int i = 1; i <= n - k + 1; i++) {
    if (mx[i - 1] <= mn[i] && mx[i + k - 1] <= mn[i + k] && l[i - 1] &&
        r[i + k]) {
      possible = true;
      break;
    }
  }
  cout << (possible ? "Yes\n" : "No\n");
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

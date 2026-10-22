#include <iostream>

using namespace std;
using ll = long long;
constexpr int maxn = 1e5 + 2;
int n;
ll a[maxn], b[maxn];

void solve() {
  cin >> n;
  ll ai, bi, idx = 0;
  for (ll i = 1; i <= n; i++)
    cin >> a[i];
  for (ll i = 1; i <= n; i++)
    cin >> b[i];
  for (ll i = 1; i <= n; i++) {
    if (a[i] > b[i]) {
      idx = i;
      break;
    }
  }
  if (idx == 0) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  for (ll i = 1; i <= n; i++) {
    cout << (i == idx ? (ll)1e18 : 1) << " \n"[i == n];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
int q, v;
priority_queue<int> h;

void solve() {
  cin >> q >> v;
  for (int i = 0; i < q; i++) {
    int a, t, w;
    cin >> a;
    if (a == 1) {
      cin >> t >> w;
      h.emplace(w - t);
    } else {
      cin >> t;
      if (h.empty()) {
        cout << -1 << '\n';
        continue;
      }
      int ans = t + h.top();
      if (ans > v)
        ans = v;
      cout << ans << '\n';
      h.pop();
    }
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

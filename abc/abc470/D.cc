#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 5e5 + 2;
int n, q, val[maxn], idx[maxn];
bool change = false;

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
    idx[val[i]] = i;
  }
  for (int i = 0; i < q; i++) {
    int t, x, y;
    cin >> t;
    if (t == 1) {
      cin >> x >> y;
      int *a = change ? idx : val;
      int *b = change ? val : idx;
      int u = a[x], v = a[y];
      swap(a[x], a[y]);
      swap(b[u], b[v]);
    } else {
      change = !change;
    }
  }
  int *ans = change ? idx : val;
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " \n"[i == n];
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

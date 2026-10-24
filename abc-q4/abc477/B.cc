#include <algorithm>
#include <iostream>

using namespace std;
using pi = pair<int, int>;
#define fi first
#define se second
constexpr int maxn = 102;
int n, d;
pi x[maxn];
int apart[maxn], idx = 0;

void solve() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> x[i].fi;
    x[i].se = i;
  }
  sort(x + 1, x + 1 + n);
  for (int i = 1; i <= n; i++) {
    if ((i == 1 && x[2].fi - x[1].fi >= d) ||
        (x[i].fi - x[i - 1].fi >= d && x[i + 1].fi - x[i].fi >= d) ||
        (i == n && x[n].fi - x[n - 1].fi >= d))
      apart[idx++] = x[i].se;
  }
  cout << idx << '\n';
  sort(apart, apart + idx);
  for (int i = 0; i < idx; i++)
    cout << apart[i] << " \n"[i == idx - 1];
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

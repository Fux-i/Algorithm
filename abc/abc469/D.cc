// -math

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n, m;

void solve() {
  cin >> n >> m;
  vector<int> A(m), B(m);
  for (int i = 0; i < m; i++)
    cin >> A[i] >> B[i];

  auto ok = [&](int p, int q) -> bool {
    for (int i = 0; i < m; i++) {
      if (A[i] != p && B[i] != p && A[i] != q && B[i] != q)
        return false;
    }
    return true;
  };

  auto cnt = [&](int p) -> ll {
    int i0 = -1;
    for (int i = 0; i < m; i++) {
      if (A[i] != p && B[i] != p) {
        i0 = i;
        break;
      }
    }
    if (i0 == -1)
      return (ll)n - 1;
    ll res = 0;
    if (ok(p, A[i0]))
      res++;
    if (ok(p, B[i0]))
      res++;
    return res;
  };

  ll ans = cnt(A[0]) + cnt(B[0]);
  if (ok(A[0], B[0]))
    ans--; // counted twice
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

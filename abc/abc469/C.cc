#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 8e5 + 2;
int n, a[maxn], b[maxn];

int fd(int x) {
  if (x == b[x]) {
    if (b[x] < n)
      b[x]++;
    return x;
  }
  return b[x] = fd(b[x]);
}

void solve() {
  string s;
  cin >> n >> s;
  iota(a, a + maxn, 0);
  iota(b, b + maxn, 0);
  for (int cnt = 0, i = 0; i < n; i++) {
    if (s[i] == 'o') {
      cnt++;
      if (b[i + 1] < n)
        b[i + 1] += 1;
    }
    a[i + 1] += cnt;
    if (a[i + 1] > n)
      a[i + 1] = n;
  }
  for (int i = 1; i <= n; i++) {
    cout << fd(a[i]) << '\n';
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

#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
int n;

void solve() {
  string s;
  cin >> n >> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o')
      continue;
    if (i == 0) {
      if (n == 1 || n > 1 && s[i + 1] == 'x')
        ans++;
    } else if (i == n - 1) {
      if (s[i - 1] == 'x')
        ans++;
    } else if (s[i - 1] == 'x' && s[i + 1] == 'x')
      ans++;
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

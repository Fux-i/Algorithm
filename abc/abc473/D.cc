#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 2e5 + 2;
int n, k;
int s[maxn];

void pt() {
  for (int i = 1; i <= n; i++)
    cout << s[i] << ' ';
  cout << '\n';
}

void dfs(int i, int rem) {
  if (i == n) {
    if (rem % n == 0) {
      s[i] = rem / n;
      pt();
    }
  } else {
    for (int v = 0; i * v <= rem; v++) {
      s[i] = v;
      dfs(i + 1, rem - i * v);
    }
  }
}

void solve() {
  cin >> n >> k;
  dfs(1, k);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

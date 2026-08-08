#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
int n, m;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0)
      cout << "Fizz\n";
    else
      cout << i << '\n';
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

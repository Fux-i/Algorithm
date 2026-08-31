#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
int n;

void solve() {
  cin >> n;
  int sum = 0, a;
  for (int i = 0; i < n / 2; i++) {
    cin >> a;
  }
  for (int i = 0; i < n / 2; i++) {
    cin >> a;
    sum += a;
  }

  cout << sum << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

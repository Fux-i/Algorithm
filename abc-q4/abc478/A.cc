#include <iostream>

using namespace std;
int n, m;

void solve() {
  cin >> n >> m;
  int d = m / n, r = m % n;
  for (int i = 1; i <= n; i++) {
    cout << (i <= r ? d + 1 : d);
    cout << '\n';
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

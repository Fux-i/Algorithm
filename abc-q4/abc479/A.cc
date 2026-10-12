#include <iostream>

using namespace std;
int n;

void solve() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    if (i & 1)
      sum += v;
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

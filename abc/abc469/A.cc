#include <iostream>

using namespace std;
int n, m;

void solve() {
  cin >> n >> m;
  cout << n + 1 - m;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

#include <iostream>

using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  cout << to_string(a + b).size();
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

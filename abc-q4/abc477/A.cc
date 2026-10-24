#include <iostream>

using namespace std;

void solve() {
  char c;
  cin >> c;
  if (c == 'B') {
    cout << 'Y';
  } else if (c == 'Y') {
    cout << 'R';
  } else
    cout << 'B';
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

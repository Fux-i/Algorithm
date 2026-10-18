#include <algorithm>
#include <iostream>
using namespace std;

void solve() {
  char a, b, c, d;
  cin >> a >> b >> c >> d;
  if (abs(a - b) == 3 || abs(a - c) == 3 || abs(d - b) == 3 || abs(d - c) == 3)
    cout << "Yes\n";
  else
    cout << "No\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

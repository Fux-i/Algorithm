#include <iostream>
#include <string>

using namespace std;
int x;

void solve() {
  cin >> x;
  if (x == 0) {
    cout << "O\n";
    return;
  }
  int q = x / 24, r = x % 24;
  string s = string(q, 'A') + string(24 - r, 'C');
  if (r > 0) {
    s += "A";
    s += string(r, 'C');
  }
  string ans = "";
  for (char c : s) {
    if (!ans.empty())
      ans += "R";
    ans += c;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

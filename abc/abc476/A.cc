#include <iostream>
#include <string>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int siz = s.size();
  s.append(s[siz - 1] == 'e' ? "r" : "er");
  cout << s << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  //cin >> T;
  while (T--) {
    solve();
  }
}

#include <iostream>
#include <string>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int siz = s.size();
  for (int i = 0; i < siz; i++) {
    cout << s[i] << "o\n"[i == siz - 1];
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

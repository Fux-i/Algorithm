#include <iostream>
#include <string>

using namespace std;
int n;

void solve() {
  string s, t;
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i] || t[i] == '*')
      continue;
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  //cin >> T;
  while (T--) {
    solve();
  }
}

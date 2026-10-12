#include <iostream>
#include <string>

using namespace std;
int n;

void solve() {
  string s;
  cin >> n >> s;
  int streak = 0, ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'S') {
      streak = 0;
    } else {
      streak++;
      ans = max(ans, streak);
    }
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

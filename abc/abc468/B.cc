#include <iostream>
#include <string>

using namespace std;
int m, d;
string s;

void solve() {
  cin >> m >> d >> s;
  auto ss = s;
  int siz = s.size();
  for (int i = 0; i < siz; i++) {
    char c = s[i];
    if (c == 'G') {
      for (int j = max(0, i - d); j <= min(siz, i + d); j++) {
        ss[j] = 'x';
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < siz; i++)
    ans += ss[i] == '.' ? 1 : 0;
  cout << ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

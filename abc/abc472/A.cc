#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second

void solve() {
  string s;
  cin >> s;
  int siz = s.size();
  for (int i = 0; i < siz; i++) {
    if (s[i] == 'A')
      cout << 'A';
    else
      cout << '.';
  }
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

#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
int n;
unordered_map<string, int> table{};

void solve() {
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int siz = s.size();
    for (int j = 0; j < siz; j++) {
      s[j] = s[j] | (1 << 5);
    }
    ans = max(ans, ++table[s]);
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

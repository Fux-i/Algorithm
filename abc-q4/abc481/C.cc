#include <iostream>
#include <unordered_map>

using namespace std;
int q;
unordered_map<string, int> m;

void solve() {
  cin >> q;
  for (int i = 1, idx = 1; i <= q; i++) {
    string s;
    cin >> s;
    if (m.contains(s))
      cout << m[s];
    else {
      m[s] = idx;
      cout << idx++;
    }
    cout << '\n';
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

#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
int h, w;

void solve() {
  cin >> h >> w;
  if (w * 10000 / (h * h) >= 25)
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

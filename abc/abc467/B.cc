#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
constexpr int maxn = 102;
int n;

void solve() {
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    if (s == "keep") {
      sum += b - a;
    }
  }
  cout << sum;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
int a, b;

void solve() {
  cin >> a >> b;
  if (a + b == 9 || a - b == 9 || a * b == 9 || (a / b == 9 && a % b == 0)) {
    cout << "Nine";
  } else {
    cout << "Nein";
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

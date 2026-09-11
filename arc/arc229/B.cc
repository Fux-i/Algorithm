#include <algorithm>
#include <iostream>

using namespace std;
int n;

void solve() {
  cin >> n;
  int prev;
  cin >> prev;
  int ans = prev > 0;
  bool possible = true;
  for (int i = 1; i < n; i++) {
    int current;
    cin >> current;
    int difference = prev - 2 * current;
    if (difference < 0) {
      possible = false;
    }
    ans = max(ans, difference);
    prev = current;
  }
  cout << (possible ? ans : -1) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}

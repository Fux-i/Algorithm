#include <cstdio>
#include <iostream>

using namespace std;
int n, c[3];

void solve() {
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    int v = a % 1000;
    int x = 1000 - v;
    c[0] += x % 10;
    c[1] += x % 100 / 10;
    c[2] += x % 1000 / 100;
  }
  printf("%d %d %d\n", c[0], c[1], c[2]);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

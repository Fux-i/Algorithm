// -interact -sliding-window

#include <iostream>
#include <string>

using namespace std;
using ll = long long;

bool query(int i, int j) {
  printf("? %d %d\n", i, j);
  fflush(stdout);
  string s;
  cin >> s;
  if (s == "Yes")
    return true;
  if (s == "No")
    return false;
  exit(1);
}

void answer(int x) {
  printf("! %d\n", x);
  fflush(stdout);
}

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  int l = 1;
  for (int j = 2; j <= n; ++j) {
    while (l < j && !query(l, j))
      ++l;
    ans += j - l;
  }
  answer(ans);
}

int main() {
//   cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  //cin >> T;
  while (T--) {
    solve();
  }
}

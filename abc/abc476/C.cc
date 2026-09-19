#include <functional>
#include <iostream>
#include <queue>

using namespace std;
constexpr int maxn = 5e5 + 2;
int n;
priority_queue<int, vector<int>, greater<>> h;

void solve() {
  cin >> n;
  for (int i = 0; i < 3; i++) {
    int v;
    cin >> v;
    h.emplace(v);
  }
  
  cout << h.top() << '\n';
  for (int i = 3; i < n; i++) {
    int v;
    cin >> v;
    if (v > h.top()) {
      h.pop();
      h.emplace(v);
    }
    cout << h.top() << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int T = 1;
  //cin >> T;
  while (T--) {
    solve();
  }
}

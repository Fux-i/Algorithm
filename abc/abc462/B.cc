#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
constexpr int maxn = 102;
int n;
vector<int> to[maxn];

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1, k, a; i <= n; ++i) {
    cin >> k;
    while (k--) {
      cin >> a;
      to[a].push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    int s = to[i].size();
    cout << s << ' ';
    for (int b : to[i])
      cout << b << ' ';
    cout << '\n';
  }
}

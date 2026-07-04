#include <deque>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;
using pii = struct {
  int a, b;
};
constexpr int maxn = 5e5 + 2;
int n;
bool flag = true;
deque<int> q;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (flag)
      q.push_back(i + 1);
    else
      q.push_front(i + 1);
    if (s[i] == 'o') {
      flag = !flag;
    }
  }
  if (flag)
    for (int i = 0; i < n; ++i)
      cout << q[i] << ' ';
  else
    for (int i = n - 1; i >= 0; --i)
      cout << q[i] << ' ';
}

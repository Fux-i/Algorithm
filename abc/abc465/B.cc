#include <iostream>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int x, y, l, r, a, b, f;
  cin >> x >> y >> l >> r >> a >> b;
  if (a >= r || b <= l) {
    f = y * (b - a);
  } else if (l <= a && b <= r) {
    f = x * (b - a);
  } else if (a <= l && r <= b) {
    f = x * (r - l) + y * (l - a + b - r);
  } else if (a <= l && b <= r) {
    f = y * (l - a) + x * (b - l);
  } else if (l <= a && r <= b) {
    f = x * (r - a) + y * (b - r);
  }
  cout << f;
}

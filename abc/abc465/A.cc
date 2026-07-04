#include <iostream>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  if (a * 3 > b * 2) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}

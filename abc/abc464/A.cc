#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  string s;
  cin >> s;
  int e = 0, w = 0;
  for (char c : s) {
    if (c == 'E')
      e++;
    else
      w++;
  }
  cout << (e > w ? "East" : "West");
}

#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  string in, out = "";
  cin >> in;
  for (int i = 0; i < in.size(); ++i) {
    if (in[i] >= '0' && in[i] <= '9')
      out.push_back(in[i]);
  }
  cout << out;
}

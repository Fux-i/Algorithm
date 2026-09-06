#include <algorithm>
#include <vector>

using namespace std;

bool np(vector<int> &v) {
  auto rbegin = v.rbegin();
  auto rend = v.rend();
  auto left = std::is_sorted_until(rbegin, rend, less<>());
  // print("left:{},", *left);
  if (left == rend) {
    // puts("");
    return false;
  }
  auto right = std::upper_bound(rbegin, left, *left);
  // print("right:{},", *right);
  swap(*left, *right);
  std::reverse(left.base(), v.end());
  for (auto i : v) {
    // print("{}", i);
  }
  // puts("");
  return true;
}

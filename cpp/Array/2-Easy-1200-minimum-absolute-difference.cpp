#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	vector<vector<int> > minimumAbsDifference(vector<int> &arr) {
		ranges::sort(arr);
		int min_diff = INT_MAX;
		vector<vector<int> > ans;
		for (int i = 1; i < arr.size(); i++) {
			int x = arr[i - 1], y = arr[i];
			int diff = y - x;
			if (diff < min_diff) {
				min_diff = diff;
				ans = {{x, y}};
			} else if (diff == min_diff) {
				ans.push_back({x, y});
			}
		}
		return ans;
	}
};

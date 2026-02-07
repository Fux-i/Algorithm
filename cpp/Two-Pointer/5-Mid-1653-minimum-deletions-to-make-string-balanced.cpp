using namespace std;

#include <string>

class Solution {
public:
	int minimumDeletions(string s) {
		int del = 0;
		for (char c : s) {
			del += 'b' - c;
		}

		int ans = del;
		for (char c : s) {
			// 'a' -> -1    'b' -> 1
			del += (c - 'a') * 2 - 1;
			ans = min(ans, del);
		}
		return ans;
	}
};
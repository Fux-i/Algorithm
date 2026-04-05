#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
		vector<int> dp(m + 1, 0);
		for (char c : word1) {
			for (int i = 0, pre = 0; i < m; ++i) {
				int temp = dp[i + 1];
				dp[i + 1] = c == word2[i] ? pre + 1 : max(dp[i], dp[i + 1]);
				pre = temp;
			}
		}
		return n + m - 2 * dp[m];
	}
};
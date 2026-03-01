#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int dp[3] = {0};
	for (char c : s) {
		if (c == 'A') {
			dp[0]++;
		} else {
			dp[c - 'A'] = min(dp[c - 'A' - 1], dp[c - 'A'] + 1);
		}
	}
	cout << dp[2] << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	string sa, ta;
	for (char c : s) if (c != 'A') sa += c;
	for (char c : t) if (c != 'A') ta += c;
	if (sa != ta) {
		cout << -1 << endl;
		return 0;
	}

	int n = s.size(), m = t.size();
	int i = 0, j = 0;
	int ans = 0;
	while (i < n || j < m) {
		int diff = 0;
		while (i < n && s[i] == 'A') {
			i++;
			diff++;
		}
		while (j < m && t[j] == 'A') {
			j++;
			diff--;
		}
		ans += abs(diff);
		if (i < n && j < m) {
			i++;
			j++;
		}
	}
	cout << ans << endl;
}

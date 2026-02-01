#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	long long cnt_same = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == s[i + 1]) cnt_same++;
	}

	long long cnt_diff = (n - 1) - cnt_same;
	long long ans = 1 + cnt_same * cnt_diff;

	cout << ans << endl;
	return 0;
}
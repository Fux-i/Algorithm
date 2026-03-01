#include <bits/stdc++.h>
using namespace std;

int main() {
	int chars[26] = {0};
	string in;
	cin >> in;

	int max_cnt = 1;
	for (char c : in) {
		chars[c - 'a']++;
		max_cnt = max(max_cnt, chars[c - 'a']);
	}
	string out{""};
	for (char c : in) {
		if (chars[c - 'a'] != max_cnt) {
			out += c;
		}
	}
	cout << out << endl;
}

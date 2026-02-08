#include <iostream>
#include <numeric>

using namespace std;

void exec() {
	int a, b;
	cin >> a >> b;
	if (b == 0) {
		if (a & 1)
			cout << 1 << " " << 11 << endl;
		else
			cout << 10 << " " << 11 << endl;
	} else if (b == 9) {
		if (a & 1)
			cout << 10 << " " << 11 << endl;
		else
			cout << 1 << " " << 11 << endl;
	} else {
		int g = gcd(b, 9);
		cout << b / g << " " << 9 / g << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		exec();
	}
}

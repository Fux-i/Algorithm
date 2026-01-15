#include <climits>

int reverse(int x) {
	long long res = 0;
	while (x != 0) {
		if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
		int pop = x % 10;
		x /= 10;
		res = res * 10 + pop;
	}
	return res;
}

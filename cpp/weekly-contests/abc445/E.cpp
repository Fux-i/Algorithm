#include <bits/stdc++.h>
#include "../../wheel/modint.hpp"
using namespace std;

using ll = long long;
constexpr ll MOD = 998244353;

using mint = modint<MOD>;
const int M = 1e7;
vector<int> lpf(M + 1);
vector<int> primes;

void init() {
	// Linear sieve
	iota(lpf.begin(), lpf.end(), 0);
	for (int x = 2; x <= M; x++) {
		if (lpf[x] == x) primes.push_back(x);
		for (int p: primes) {
			if ((ll) p * x > M || p > lpf[x]) break;
			lpf[p * x] = p;
		}
	}
}

void solve() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	// e1[p]=e_1(p), e2[p]=e_2(p)
	map<int, int> e1, e2;
	// Compute e_1(p) and e_2(p)
	for (int i = 0; i < N; i++) {
		int x = A[i];
		while (x > 1) {
			int p = lpf[x], e = 0;
			while (x % p == 0) x /= p, e++;
			if (e > e1[p])
				e2[p] = e1[p], e1[p] = e;
			else if (e > e2[p])
				e2[p] = e;
		}
	}

	// Find LCM(A_1,...,A_N)
	mint lcm = 1;
	for (auto &[p, e]: e1) lcm *= mint(p).pow(e);

	// Find the answer
	for (int i = 0; i < N; i++) {
		mint ans = lcm;
		int x = A[i];
		while (x > 1) {
			int p = lpf[x], e = 0;
			while (x % p == 0) x /= p, e++;
			if (e == e1[p]) ans /= mint(p).pow(e1[p] - e2[p]);
		}
		cout << ans.val() << " \n"[i + 1 == N];
	}
}

int main() {
	init();

	ll T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}

// big div 除法
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
constexpr ll MOD = 10007;
const ll LOG = 35;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

ll K, M;
ll f[10][LOG][10005], g[10][LOG][10005], p[LOG];
bool computed[10] = {false};

ll pow10_mod(ll exp, ll mod) {
	ll res = 1, base = 10 % mod;
	while (exp) {
		if (exp & 1) res = res * base % mod;
		base = base * base % mod;
		exp >>= 1;
	}
	return res;
}

void precompute(ll digit) {
	if (computed[digit]) return;
	computed[digit] = true;
	for (ll r = 0; r < M; r++) {
		ll cur = r * 10 + digit;
		f[digit][0][r] = cur % M;
		g[digit][0][r] = cur / M;
	}
	for (ll j = 1; j < LOG; j++) {
		for (ll r = 0; r < M; r++) {
			f[digit][j][r] = f[digit][j-1][f[digit][j-1][r]];
			g[digit][j][r] = (g[digit][j-1][r] * p[j-1] + g[digit][j-1][f[digit][j-1][r]]) % MOD;
		}
	}
}

void solve() {
	K = read(); M = read();
	p[0] = 10 % MOD;
	for (ll j = 1; j < LOG; j++) p[j] = p[j-1] * p[j-1] % MOD;

	ll quotient = 0, remainder = 0;
	for (ll i = 0; i < K; i++) {
		ll digit = read(), cnt = read();
		precompute(digit);
		ll temp_q = 0, temp_r = remainder;
		for (ll j = LOG - 1; j >= 0; j--) {
			if (cnt & (1LL << j)) {
				temp_q = (temp_q * p[j] + g[digit][j][temp_r]) % MOD;
				temp_r = f[digit][j][temp_r];
			}
		}
		ll pow10_cnt = pow10_mod(cnt, MOD);
		quotient = (quotient * pow10_cnt + temp_q) % MOD;
		remainder = temp_r;
	}
	print(quotient);
}

int main() {
	solve();
}

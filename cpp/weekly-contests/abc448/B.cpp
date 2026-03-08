#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

int main() {
	ll n = read(), m = read();
	vector<ll> c(m + 1);
	for (ll i = 1; i <= m; ++i) {
		c[i] = read();
	}
	vector<ll> table(m + 1, 0);
	while (n--) {
		ll a = read(), b = read();
		table[a] += b;
	}
	ll ans = 0;
	for (ll i = 1; i <= m; ++i) {
		ans += min(c[i], table[i]);
	}
	print(ans);
}
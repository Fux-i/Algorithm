#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

int main() {
	ll l = read(), r = read(), d = read(), u = read();
	ll ans = 0;
	for (ll i = l + 1 & ~1; i <= r; i += 2) {
		ll ub = abs(i), db = -ub;
		ub = min(ub, u);
		db = max(db, d);
		if (ub >= db) ans += ub - db + 1;
	}
	for (ll i = d + 1 & ~1; i <= u; i += 2) {
		ll rb = abs(i), lb = -rb;
		rb = min(rb, r);
		lb = max(lb, l);
		if (lb > rb) continue;
		ll exclude = 0;
		if (i >= l && i <= r) exclude++;
		if (-i >= l && -i <= r && i != 0) exclude++;
		ans += (rb - lb + 1) - exclude;
	}
	print(ans);
}
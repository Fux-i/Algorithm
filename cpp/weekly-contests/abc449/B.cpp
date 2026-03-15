#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

ll h, m, t;

void query() {
	ll type = read(), cnt = read();
	if (type == 1) {
		print(m * cnt);
		h -= cnt;
	} else {
		print(h * cnt);
		m -= cnt;
	}
}

int main() {
	h = read(); m = read(), t = read();
	while (t--) {
		query();
	}
}
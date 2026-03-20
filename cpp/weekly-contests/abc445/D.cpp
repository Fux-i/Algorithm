#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define all(a) a.begin(), a.end()

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

int main() {
	ll h = read(), w = read(), n = read();
	vector<pll> blocks(n);
	for (ll i = 0; i < n; i++) {
		blocks[i].first = read();
		blocks[i].second = read();
	}
	vector<bool> used(n, false);
	vector<ll> hs(n), ws(n);
	iota(all(hs), 0);
	iota(all(ws), 0);
	ranges::sort(hs, [&](ll &a, ll &b){return blocks[a].first > blocks[b].first;}, {});
	ranges::sort(ws, [&](ll &a, ll &b){return blocks[a].second > blocks[b].second;}, {});


	vector<pll> pos(n);
	ll ranged = 0, x = 1, y = 1;
	auto ith = hs.begin();
	auto itw = ws.begin();
	while (ranged < n) {
		while (used[*ith]) ++ith;
		if (h - x + 1 == blocks[*ith].first) {
			pos[*ith].first = x; pos[*ith].second = y;
			y += blocks[*ith].second;
			used[*ith] = true;
			++ith;
			ranged++;
			continue;
		}
		while (used[*itw]) ++itw;
		if (w - y + 1 == blocks[*itw].second) {
			pos[*itw].first = x; pos[*itw].second = y;
			x += blocks[*itw].first;
			used[*itw] = true;
			++itw;
			ranged++;
		}
	}
	for (ll i = 0; i < n; ++i) {
		pt(pos[i].first);
		putchar(' ');
		pt(pos[i].second);
		puts("");
	}
}

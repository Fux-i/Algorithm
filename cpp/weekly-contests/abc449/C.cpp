#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

int main() {
	int n = (int)read(), l = (int)read(), r = (int)read();
	char s[500005];
	scanf("%s", s);
	vector<vector<int>> table(26);

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int c = s[i] - 'a';
		auto &t = table[c];
		int min_pos = i - r;
		int max_pos = i - l;
		if (max_pos >= 0) {
			auto begin = ranges::lower_bound(t, min_pos);
			auto end = ranges::upper_bound(t, max_pos);
			ans += end - begin;
		}
		t.push_back(i);
	}
	print(ans);
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}


int main() {
	ll n = read();
	vector<string> ss(n);
	ll len = 0;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		ss[i] = s;
		len = max(len, (ll)s.size());
	}
	for (ll i = 0; i < n; i++) {
		ll m = ss[i].size();
		ll fix = (len - m) / 2;
		cout << string(fix, '.') << ss[i] << string(fix, '.') << endl;
	}
}

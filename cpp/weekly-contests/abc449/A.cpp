#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
constexpr db PI = 3.14159265358979323;
//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}

int main() {
	db d = read();
	db r = d / 2;
	cout << fixed << setprecision(15) << PI * r * r;
}
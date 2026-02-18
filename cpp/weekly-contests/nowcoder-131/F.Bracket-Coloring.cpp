#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ne " -> "
#define sep "======"
#define fastio ios::sync_with_stdio(false);cin.tie(0);
#define all(a) a.begin(), a.end()

using ll = long long;
using ull = unsigned long long;
using db = long double;
typedef long double db;
typedef pair<long long,long long> PLL;
typedef tuple<ll,ll,ll> TLLL;
constexpr ll INF = (ll)2e18+9;
constexpr ll MOD = 1000000007;
//constexpr ll MOD = 998244353;
constexpr db PI = 3.14159265358979323;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}
inline void print(PLL x){pt(x.fi), putchar(' '), pt(x.se), putchar('\n');}
inline void print(vector<ll> &vec){for(const auto t:vec)pt(t),putchar(' ');puts("");}
inline void print(const map<ll, ll>& g) {for(const auto& [key, value]:g){cout<<"key: "<<key<<ne<<value<<" ";}puts("");}
inline void print(vector<PLL> &vec){puts(sep);for(const auto v:vec){print(v);}puts(sep);}
inline void print(const map<ll, vector<ll>>& g) {for (const auto& [key, value] : g) { cout << "key: " << key << ne;for (const auto& v : value) {cout << v << " ";}cout << endl;}}

//fast pow
ll ksm(ll a, ll b=MOD-2, ll M=MOD){a%=M;ll res=1;while(b){if(b&1){res=(res*a)%M;}a=(a*a)%M;b>>=1;}return res;}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//rng()
ull randint(ull l, ull r){uniform_int_distribution<unsigned long long> dist(l, r);return dist(rng);}

void init(){

}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<ll> left(n + 1);
    vector<ll> stk;
    for (ll i = 1; i <= n; i++) {
        if (s[i] == '(') stk.pb(i);
        else left[i] = stk.back(), stk.pop_back();
    }
    vector<vector<ll> > g(n + 1);
    for (ll i = 1; i <= n; i++) {
        if (s[i] == s[i - 1]) {
            if (s[i] == '(') {
                g[i].pb(i - 1);
                g[i - 1].pb(i);
            } else {
                g[left[i]].pb(left[i - 1]);
                g[left[i - 1]].pb(left[i]);
            }
        }
    }
    ll cnt = 0;
    vector<ll> vis(n + 1);
    for (ll i = 1; i <= n; i++) {
        if (s[i] == '(' && !vis[i]) {
            cnt++;
            queue<ll> q;
            q.push(i);
            while (!q.empty()) {
                auto u = q.front();
                q.pop();
                vis[u] = 1;
                for (auto v: g[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    print(ksm(2, cnt));
}


int main() {
    init();
    ll t = 1;
    t = read();
    while (t--) {
        solve();
    }
}

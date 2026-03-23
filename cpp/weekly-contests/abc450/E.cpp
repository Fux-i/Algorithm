#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using db = long double;
constexpr ll INF = (ll)2e18+9;
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr db PI = 3.14159265358979323;

// io functions
// ios::sync_with_stdio(false); cin.tie(nullptr);
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

#define fi first
#define se second
#define all(a) a.begin(), a.end()
inline void print(pll x){pt(x.fi), putchar(' '), pt(x.se), putchar('\n');}
inline void print(vector<ll> &vec){for(const auto t:vec)pt(t),putchar(' ');puts("");}

//fast pow
ll ksm(ll a, ll b=MOD-2, ll M=MOD){a%=M;ll res=1;while(b){if(b&1){res=(res*a)%M;}a=(a*a)%M;b>>=1;}return res;}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//rng()
ull randint(ull l, ull r){uniform_int_distribution<unsigned long long> dist(l, r);return dist(rng);}

const int MAX_N = 100;

string X, Y;
ll len[MAX_N + 1];
ll cnt[MAX_N + 1][26];

ll countChar(int n, ll r, int c) {
    if (r <= 0) return 0;
    if (n == 1) {
        ll res = 0;
        for (ll i = 0; i < min((ll) X.size(), r); i++) {
            if (X[i] == 'a' + c) res++;
        }
        return res;
    }
    if (n == 2) {
        ll res = 0;
        for (ll i = 0; i < min((ll) Y.size(), r); i++) {
            if (Y[i] == 'a' + c) res++;
        }
        return res;
    }
    if (r >= len[n]) {
        return cnt[n][c];
    }
    // S_n = S_{n-1} + S_{n-2}
    if (r <= len[n - 1]) {
        return countChar(n - 1, r, c);
    } else {
        return cnt[n - 1][c] + countChar(n - 2, r - len[n - 1], c);
    }
}

void solve() {
    cin >> X >> Y;

    ll Q;
    cin >> Q;

    len[1] = (ll) X.size();
    len[2] = (ll) Y.size();

    memset(cnt, 0, sizeof(cnt));
    for (int c = 0; c < 26; c++) {
        for (char ch: X) {
            if (ch == 'a' + c) cnt[1][c]++;
        }
        for (char ch: Y) {
            if (ch == 'a' + c) cnt[2][c]++;
        }
    }

    ll target = 1000000000000000000LL;
    int N = 2;
    for (int i = 3; i <= MAX_N; i++) {
        // Check for overflow BEFORE adding
        if (len[i - 1] > (ll) 2e18 || len[i - 2] > (ll) 2e18) {
            len[i] = (ll) 2e18 + 7; // Cap at safe value
        } else {
            len[i] = len[i - 1] + len[i - 2];
        }
        for (int c = 0; c < 26; c++) {
            cnt[i][c] = cnt[i - 1][c] + cnt[i - 2][c];
        }
        if (len[i] >= target) {
            N = i;
            break;
        }
    }

    // Process queries
    while (Q--) {
        ll L, R;
        char C;
        cin >> L >> R >> C;
        int c = C - 'a';

        ll ans = countChar(N, R, c) - countChar(N, L - 1, c);
        print(ans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

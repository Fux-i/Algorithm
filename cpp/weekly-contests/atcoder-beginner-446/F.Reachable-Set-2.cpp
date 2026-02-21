//graph
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()

using ll = long long;

//io functions
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}
inline ll read(){ll x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;return x;}
inline void pt(ll x){if(x<0) putchar('-'),x=-x;if(x>9) pt(x/10);putchar(x%10+'0');}
inline void print(ll x){pt(x), puts("");}

ll N, M;
vector<bool> vertices;
ll num_vertices = 0;
vector<bool> reachable;
ll num_reachable = 1;
vector<vector<ll>> edges;

void init(){
    vertices.assign(N + 1, false);
    reachable.assign(N + 1, false);
    reachable[1] = true;

    edges.assign(N + 1, vector<ll>{});
    while (M--) {
        ll u = read(), v = read();
        edges[u].emplace_back(v);
    }
}

void solve() {
    for (ll k = 1; k <= N; ++k) {
        if (!reachable[k]) {
            print(-1);
            continue;
        }
        if (!vertices[k]) {
            vertices[k] = true;
            num_vertices++;
            vector<ll> vs(edges[k]);
            while (!vs.empty()) {
                ll v = vs.back();
                vs.pop_back();
                if (!reachable[v]) {
                    reachable[v] = true;
                    num_reachable++;
                }
                if (num_vertices < k && v < k && !vertices[v]) {
                    vertices[v] = true;
                    num_vertices++;
                    vs.insert(vs.end(), all(edges[v]));
                }
            }
            if (num_vertices < k) {
                print(-1);
                continue;
            }
        }
        print(num_reachable - num_vertices);
    }
}


int main() {
    N = read();
    M = read();
    init();
    solve();
}

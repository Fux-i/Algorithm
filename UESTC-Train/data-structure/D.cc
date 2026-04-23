#include <bits/stdc++.h>

#define m ((r - l >> 1) + l)
#define lc (idx << 1)
#define rc ((idx << 1) + 1)

using namespace std;
using ll = long long;

class segtree {
	struct Node {
		ll val = 0;
		ll max = 0;
		ll mul = 1;
		ll add = 0;
	};

	vector<Node> tree;

	void apply(ll idx, ll l, ll r, ll mul, ll add) {
		Node &o = tree[idx];
		o = {
			o.val * mul + add * (r - l + 1),
			o.max * mul + add,
			o.mul * mul,
			o.add * mul + add
		};
	}

	void push(ll idx, ll l, ll r) {
		Node &o = tree[idx];
		if (o.mul != 1 || o.add != 0) {
			apply(lc, l, m, o.mul, o.add);
			apply(rc, m + 1, r, o.mul, o.add);
			o.mul = 1;
			o.add = 0;
		}
	}

	void pop(ll idx) {
		tree[idx].val = tree[lc].val + tree[rc].val;
		tree[idx].max = max(tree[lc].max, tree[rc].max);
	}

public:
	segtree(vector<ll> &origin, ll n) : tree(n * 4) {
		auto build = [&](auto &&build, ll idx, ll l, ll r) -> void {
			if (l == r) {
				tree[idx].val = tree[idx].max = origin[l];
				return;
			}
			build(build, lc, l, m);
			build(build, rc, m + 1, r);
			pop(idx);
		};
		build(build, 1, 1, n);
	}

	void range_add(ll idx, ll l, ll r, ll rl, ll rr, ll add) {
		if (rl <= l && r <= rr) {
			tree[idx].val += add * (r - l + 1);
			tree[idx].max += add;
			tree[idx].add += add;
			return;
		}
		push(idx, l, r);
		if (rl <= m) range_add(lc, l, m, rl, rr, add);
		if (rr > m) range_add(rc, m + 1, r, rl, rr, add);
		pop(idx);
	}

	void range_ass(ll idx, ll l, ll r, ll rl, ll rr, ll ass) {
		if (rl <= l && r <= rr) {
			tree[idx] = {ass * (r - l + 1), ass, 0, ass};
			return;
		}
		push(idx, l, r);
		if (rl <= m) range_ass(lc, l, m, rl, rr, ass);
		if (rr > m) range_ass(rc, m + 1, r, rl, rr, ass);
		pop(idx);
	}

	void range_mul(ll idx, ll l, ll r, ll rl, ll rr, ll mul) {
		if (rl <= l && r <= rr) {
			tree[idx].val *= mul;
			tree[idx].max *= mul;
			tree[idx].mul *= mul;
			tree[idx].add *= mul;
			return;
		}
		push(idx, l, r);
		if (rl <= m) range_mul(lc, l, m, rl, rr, mul);
		if (rr > m) range_mul(rc, m + 1, r, rl, rr, mul);
		pop(idx);
	}

	ll query_sum(ll idx, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[idx].val;
		}
		push(idx, l, r);
		ll sum = 0;
		if (ql <= m) sum = query_sum(lc, l, m, ql, qr);
		if (qr > m) sum += query_sum(rc, m + 1, r, ql, qr);
		pop(idx);
		return sum;
	}

	ll query_max(ll idx, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[idx].max;
		}
		push(idx, l, r);
		ll max_val = 0;
		if (ql <= m) max_val = query_max(lc, l, m, ql, qr);
		if (qr > m) max_val = max(max_val, query_max(rc, m + 1, r, ql, qr));
		pop(idx);
		return max_val;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N, M;
	cin >> N >> M;
	vector<ll> origin(N + 1);
	for (ll i = 1; i <= N; ++i) cin >> origin[i];
	segtree s(origin, N);

	vector<vector<ll> > queries(M, vector<ll>(4));
	for (ll i = 0; i < M; ++i) {
		cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
		if (queries[i][0] < 4) cin >> queries[i][3];
	}
	vector<ll> ans;
	for (auto &q: queries) {
		ll type = q[0];
		if (type == 1) s.range_add(1, 1, N, q[1], q[2], q[3]);
		else if (type == 2) s.range_ass(1, 1, N, q[1], q[2], q[3]);
		else if (type == 3) s.range_mul(1, 1, N, q[1], q[2], q[3]);
		else if (type == 4) ans.push_back(s.query_sum(1, 1, N, q[1], q[2]));
		else ans.push_back(s.query_max(1, 1, N, q[1], q[2]));
	}
	for (auto a : ans) {
		cout << a << '\n';
	}
	ll as = ans.size();
	for (ll i = 0; i < as - 1; ++i) {
		cout << ans[i] << "\n";
	}
	cout << ans[as - 1];
}

/*
5 7
1 2 3 4 5
1 1 3 2
3 2 4 3
4 1 5
5 2 4
2 1 3 0
4 1 5
5 1 5

47
15
17
12

5 7
1 2 3 4 5
1 1 5 2
3 1 4 3
4 1 5
5 1 5
2 2 4 1
4 1 5
5 1 5


*/

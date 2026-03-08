#pragma once
#include <vector>

using ll = long long;

// Segment tree for range sum with lazy propagation
class segtree {
	struct Node {
		ll val;   // sum of the range represented by this node
		ll todo;  // lazy tag: value to be added to all elements in this range
	};

public:
	// Constructor: builds the segment tree from vector v
	// v: initial array of values
	explicit segtree(const std::vector<ll>& v) : n(v.size()), tree(4 * v.size()) {
		build(v, 0, 0, n - 1);
	}
	// Query the sum of range [l, r]
	ll query(ll l, ll r) {
		return range_query(0, 0, n - 1, l, r);
	}
	// Add x to all elements in range [l, r]
	void update(ll l, ll r, ll x) {
		range_update(0, 0, n - 1, l, r, x);
	}

private:
	ll n;                    // size of the original array
	std::vector<Node> tree;  // segment tree stored as array

	// Build the segment tree recursively
	void build(const std::vector<ll>& v, ll idx, ll l, ll r) {
		if (l == r) {
			tree[idx].val = v[l];
			tree[idx].todo = 0;
			return;
		}
		ll m = l + (r - l) / 2;
		build(v, idx * 2 + 1, l, m);
		build(v, idx * 2 + 2, m + 1, r);
		tree[idx].val = tree[idx * 2 + 1].val + tree[idx * 2 + 2].val;
		tree[idx].todo = 0;
	}
	// Recursive range query
	ll range_query(ll idx, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) return tree[idx].val;  // fully covered
		push(idx, l, r);
		ll m = l + (r - l) / 2;
		ll sum = 0;
		if (ql <= m) sum += range_query(idx * 2 + 1, l, m, ql, qr);
		if (qr > m) sum += range_query(idx * 2 + 2, m + 1, r, ql, qr);
		return sum;
	}
	// Recursive range update
	void range_update(ll idx, ll l, ll r, ll ul, ll ur, ll x) {
		if (ul <= l && r <= ur) {  // fully covered
			apply(idx, l, r, x);
			return;
		}
		push(idx, l, r);
		ll m = l + (r - l) / 2;
		if (ul <= m) range_update(idx * 2 + 1, l, m, ul, ur, x);
		if (ur > m) range_update(idx * 2 + 2, m + 1, r, ul, ur, x);
		tree[idx].val = tree[idx * 2 + 1].val + tree[idx * 2 + 2].val;
	}
	// Push lazy tag to children
	void push(ll idx, ll l, ll r) {
		if (tree[idx].todo == 0) return;
		ll m = l + (r - l) / 2;
		apply(idx * 2 + 1, l, m, tree[idx].todo);
		apply(idx * 2 + 2, m + 1, r, tree[idx].todo);
		tree[idx].todo = 0;
	}
	// Apply lazy update to a node
	void apply(ll idx, ll l, ll r, ll x) {
		tree[idx].val += (r - l + 1) * x;  // update sum: (range length) * x
		tree[idx].todo += x;               // set lazy tag
	}
};
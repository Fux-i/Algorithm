#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *prv, *nxt;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;

	Node *head = new Node(0), *tail = new Node(0);
	head->nxt = tail, tail->prv = head;
	unordered_map<int, Node *> tbl{};
	vector<int> seq(n + 1, 0), team(n + 1, 0);

	Node *temp = head;
	for (int i = 1; i <= n; ++i) {
		int v;
		cin >> v;
		seq[i] = v;
		Node *o = new Node(v, temp, temp->nxt);
		o->prv->nxt = o;
		o->nxt->prv = o;
		tbl[v] = o;
		temp = o;
	}

	for (int i = 1, top = n; ; i = 3 - i) {
		while (team[top] != 0) top--;
		if (top < 1) break;

		team[top] = i;
		Node *o = tbl[top];
		Node *l = o->prv, *r = o->nxt;
		for (int j = 0; j < k && l->val > 0; ++j) {
			team[l->val] = i;
			l = l->prv;
		}
		for (int j = 0; j < k && r->val > 0; ++j) {
			team[r->val] = i;
			r = r->nxt;
		}
		l->nxt = r, r->prv = l;
	}

	for (int i = 1; i <= n; ++i) cout << team[seq[i]];
}

/*
7 1
7 2 1 3 5 4 6


*/

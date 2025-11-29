#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > ans{};
vector<int> one{};

vector<vector<int> > graph;

void dfs(int node, int target) {
    one.push_back(node);
    if (node == target) {
        ans.push_back(one);
    }
    vector<int> next = graph[node];
    for (int n: next) {
        dfs(n, target);
    }
    one.pop_back();
}

int main() {
    int N, M;
    cin >> N >> M;
    graph.assign(N + 1, {});
    while (M--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dfs(1, N);

    if (ans.size() > 0)
        for (auto &a: ans) {
            for (int i = 0; i < a.size(); i++) {
                if (i != 0) cout << ' ';
                cout << a[i];
            }
            cout << '\n';
        }
    else cout << -1;
}

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using graph = vector<vector<ll>>;

void dfs(ll u, const graph &g, vector<bool> &visited) {
    visited[u] = true;
    for (auto el : g[u]) {
        ll next = el;
        if (!visited[el])
            dfs(next, g, visited);
  }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<bool> visited(n, false);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll c = 0;
    for (ll i =0; i <n; ++i) {
        if (!visited[i]) {
            ++c;
            dfs(i,g,visited);
        }
    }
    cout << c << endl;
    return 0;
}

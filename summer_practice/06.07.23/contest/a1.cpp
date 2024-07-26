#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using graph = vector<vector<ll>>;


bool dfs(ll u, ll v, graph &g, vector<bool> &visited, vector <ll> &path) {
    visited[u] = true;
    path.push_back(u);
    if (u == v) {
        return true;
    }
    for (ll i = 0; i < g[u].size(); i++) {
        ll next = g[u][i];
        if (!visited[next]) {
            if (dfs(next, v, g, visited, path))
                return true;
        }
    }
    path.pop_back();
    return false;
}

int main() {
    ll n, m, u, v;
    cin >> n >> m >> u >> v;
    vector<vector<ll>> g(n+1);
    vector<bool> visited(n+1);
    vector<ll> path;
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (dfs(u, v, g, visited, path)) {
        for (ll i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
    } else {
        cout << -1;
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using graph = vector<vector<ll>>;

void dfs(ll u, const graph &g, vector<bool> &visited, vector<ll> &ans) {
    visited[u] = true;
    for (auto el : g[u]) {
        if (!visited[el])
            dfs(el, g, visited, ans);
    }
    ans.push_back(u);
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
    }
    vector<bool> visited(n, false);
    vector<ll> ans;
    for (ll i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, g, visited, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto l : ans) {
        cout << l +1 << ' ';
    }
    cout << endl;
    return 0;
}

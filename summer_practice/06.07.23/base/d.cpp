#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using ll= long long;
using graph = vector<vector<ll>>;

const ll INF = 1e10;
ll N = 0;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;


bool dfs(ll u, ll prev, const graph &g, vector<int> &color,
         vector<ll> &path, vector<ll> &cycle) {
    if (color[u] == BLACK) return false;
    if (color[u] == GRAY) return true;
    color[u] = GRAY;
    path.push_back(u);
    for (auto v : g[u]) {
        if (v == prev) continue;
        bool tmp = dfs(v, u, g, color, path, cycle);
        if (tmp and cycle.empty()) {
            ll ind = path.size() - 1;
            cycle.push_back(v);
            while (path[ind] != v) {
                cycle.push_back(path[ind]);
                --ind;
            }
            return true;
        }
    }
    color[u] = BLACK;
    path.pop_back();
    return false;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    graph g(n);
    for (ll i = 0; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll start = 0;
    vector<int> color(n);
    vector<ll> path;
    vector<ll> cycle;
    dfs(start, -1, g, color, path, cycle);
    sort(cycle.begin(), cycle.end());
    for (auto el : cycle) {
        cout << el + 1 << ' ';
    }
    cout << endl;
    return 0;
}

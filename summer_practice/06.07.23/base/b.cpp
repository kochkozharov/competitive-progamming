#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
using ll= long long;
using graph = vector<vector<ll>>;
 
const ll INF = 1e10;
 
void bfs(const graph &g, ll u, vector<ll> &d, vector<ll> &prev) {
    ll n = g.size();
    d.assign(n, INF);
    prev.assign(n, -1);
    d[u] = 0;
    queue<ll> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (ll v : g[u]) {
            if (d[v] < INF) continue;
            prev[v] = u;
            d[v] =d[u]+1;
            q.push(v);
        }
    }
}
 
int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    graph g(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> d, prev;
    bfs(g, k-1, d, prev);
 
    for (ll elem : d) {
        elem = (elem == INF) ? -1 : elem;
        cout << elem << ' ';
    }
    cout << endl;
}

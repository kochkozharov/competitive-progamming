#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using ll= long long;

struct wedge {
    ll u, v;
    ll w;
    wedge(ll _u, ll _v, ll _w) : u(_u), v(_v), w(_w) {}
};

using wgraph = vector<vector<wedge>>;

using item = pair<ll, ll>;

const ll INF = 1e18;

void dijkstra(ll u, const wgraph &g, vector<ll> &d, vector<ll> &prev) {
    ll n = g.size();
    d[u] = 0;
    priority_queue<item, vector<item>, greater<item>> pq;
    pq.push(make_pair(0, u));
    vector<bool> visited(n, false);
    while (!pq.empty()) {
        item cur = pq.top();
        pq.pop();
        u = cur.second;
        if (visited[u]) continue;
        visited[u] = true;
        for (wedge uv :  g[u]) {
            ll v = uv.v;
            ll w = uv.w;
            if (u == v) continue;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                prev[v] = u;
                pq.push(make_pair(d[v], v));
            }
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m, start, finish;
    cin >> n >> m >> start >> finish;
    start--; finish--;
    wgraph g(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(u, v, 0);
        g[v].emplace_back(v, u, 1);
    }
    vector<ll> d(n, INF);
    vector<ll> prev(n, -1);
    dijkstra(start, g, d, prev);
    cout << d[finish] << endl;
    return 0;
}

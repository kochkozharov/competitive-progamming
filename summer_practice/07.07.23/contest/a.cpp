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
    d[u] = INF;
    priority_queue<item, vector<item>, less<item>> pq;
    pq.push(make_pair(INF, u));
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
            if (v == u) continue;
            if (min(d[u], w) > d[v]) {
                d[v] = min(d[u], w);
                prev[v] = u;
                pq.push(make_pair(d[v], v));
            }
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m, start;
    cin >> n >> m >> start;
    start--;
    wgraph g(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].emplace_back(u, v, w);
        g[v].emplace_back(v, u, w);
    }
    vector<ll> d(n, 0);
    vector<ll> prev(n, -1);
    dijkstra(start, g, d, prev);
    d[start] = -1;
    for (ll el : d) {
        if (el == INF) cout <<  0 << ' ';
        else cout << el  << ' ';
    }
    cout << endl;
    return 0;
}

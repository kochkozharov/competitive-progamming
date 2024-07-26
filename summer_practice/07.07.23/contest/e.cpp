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

void dijkstra(const vector<ll> &bunk, const wgraph &g, vector<ll> &d) {
    ll n = g.size();
    priority_queue<item, vector<item>, greater<item>> pq;
    for (ll u : bunk) {
        d[u] = 0;
        pq.push(make_pair(0, u));
    }
    vector<bool> visited(n, false);
    while (!pq.empty()) {
        item cur = pq.top();
        pq.pop();
        ll u = cur.second;
        if (visited[u]) continue;
        visited[u] = true;
        for (wedge uv :  g[u]) {
            ll v = uv.v;
            ll w = uv.w;
            if (u == v) continue; //
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push(make_pair(d[v], v));
            }
        }
    }
}

void solve() {
    ll m, n, k, d;
    cin >> n >> m >> k >> d;
    vector<ll> dist(n, INF);
    vector<ll> bunk(k);
    wgraph g(n);
    for (ll i = 0; i < k; ++i) {
        cin >> bunk[i];
        bunk[i]--;
    }
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[v].emplace_back(v, u, w);
    }
    dijkstra(bunk, g, dist);
    vector<ll> cities;
    for (ll i = 0; i < n; ++i) {
        if (dist[i] <= d)
            cities.push_back(i);
    }
    sort(cities.begin(), cities.end());
    for (auto city : cities) {
        cout << city +1 << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
 
using ll= long long;
using graph = vector<vector<ll>>;
 
const ll INF = 1e18;
 
void bfs(ll s1, ll s2, graph &g, vector<ll> &d, vector<ll> &prev) {
    ll n = g.size();
    d.assign(n, INF);
    prev.assign(n, -1);
    d[s1] = 0;
    d[s2] = 0;
    queue<ll> q;
    q.push(s1);
    q.push(s2);
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (auto l : g[u]) {
            ll v = l.first;
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
    ll m;
    cin >> m;
    graph g(2000);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }
    ll finish, s1, s2;
    cin >> finish >> s1 >> s2;
    finish--; s1--; s2--;
    vector<ll> d, prev;
    bfs(s1, s2, g, d, prev);
    if (prev[finish] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<ll> path;
    ll u = finish;
    while(1) {
        if (prev[u] == -1) break;
        path.push_back(g[u][prev[u]].second);
        u = prev[u];
    }
    reverse(path.begin(), path.end());
    for (ll el : path) {
        cout << el << ' ';
    }
    cout << endl;
}

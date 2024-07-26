#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
 
using ll= long long;
using graph = vector<vector<pair<ll, ll>>>;
 
const ll INF = 1e18;
 
void bfs(ll s1, ll s2, graph &g, vector<ll> &d, vector<pair<ll, ll>> &prev) {
    ll n = g.size();
    d.assign(n, INF);
    prev.assign(n, make_pair(-1, 0));
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
            prev[v].first =  u;
            prev[v].second = l.second;
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
        g[u].push_back(make_pair(v,i+1));
    }
    ll finish, s1, s2;
    cin >> finish >> s1 >> s2;
    finish--; s1--; s2--;
    vector<ll> d; vector<pair<ll,ll>>prev;
    bfs(s1, s2, g, d, prev);
    if (prev[finish].first == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<ll> path;
    ll u = finish;
    while(prev[u].first != -1) {
        path.push_back(prev[u].second);
        u = prev[u].first;
    }
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (ll el : path) {
        cout << el << '\n';
    }
}

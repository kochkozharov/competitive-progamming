#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ll= long long;
struct wedge {
    ll u, v;
    ll w;
    wedge(ll _u, ll _v, ll _w) : u(_u), v(_v), w(_w) {}
};
const ll INF = 1e18;

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m, start;
    cin >> n >> m >> start;
    start--;
    vector<wedge> e;
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        e.emplace_back(u, v, w);
    }
    vector<ll> dp(n, INF);
    dp[start] = 0;
    bool changed = true;
    for (ll i = 0; i < n and changed; ++i) {
        changed = false;
        for (wedge &el : e) {
            ll u = el.u;
            ll v = el.v;
            ll w = el.w;
            if (dp[u] + w < dp[v]) {
                changed = true;
                dp[v] = dp[u] + w;
            }
        }
    }
    if (changed) {
        cout << "Negative cycle\n";
        return 0;
    }
    for (ll el : dp) {
        if (el < INF) {
            cout << el << ' ';
        }
        else {
            cout << "inf ";
        }
    }
    cout << endl;
    return 0;
}

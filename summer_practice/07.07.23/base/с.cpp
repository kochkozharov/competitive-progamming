#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using ll= long long;

using wgraph = vector<vector<ll>>;

const ll INF = 1e18;

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    wgraph g(n, vector<ll>(n, INF));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    for (ll u = 0; u < n; ++u) {
        g[u][u] = 0;
    }
    for (ll k = 0; k < n; ++k) {
        for (ll u = 0; u < n; ++u) {
            for (ll v = 0; v < n; ++v)
                g[u][v] = min(g[u][v], g[u][k] + g[k][v]);
        }
    }
    for (ll u = 0; u < n; ++u) {
        for (ll v = 0; v < n; ++v) {
            if (g[u][v] < INF) 
                cout << g[u][v] << ' ';
            else cout << "inf ";
        }
        cout << '\n';
    }

    return 0;
}

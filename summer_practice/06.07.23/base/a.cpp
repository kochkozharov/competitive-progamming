#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ll= long long;
using graph = vector<vector<ll>>;

const ll INF = 1e10;
ll N = 0;

void dfs(ll k, graph &g, vector<bool> &usd, vector<ll> &ans) {
    usd[k] = true;
    ans[k] = N;
    N++;
    for (auto el : g[k]) {
        if (!usd[el])
            dfs(el, g, usd, ans);
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    k--;
    graph g(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> usd(n);
    vector<ll> ans(n, -1);
    dfs(k, g, usd, ans);
    for (auto l : ans) {
        cout << l << ' ';
    }
    cout << endl;
    return 0;
}

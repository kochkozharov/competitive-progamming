#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using graph = vector<vector<ll>>;
using grid = vector<string>;

struct cord {
    ll x,y;
};

const ll INF = 1e10;

inline bool check(ll x, ll y, ll n, ll m) {
    return (0 <= x and x < n) and (0 <= y and y < m);
}

void bfs(const grid &g, cord u, vector<vector<ll>> &d) {
    ll n = g.size();
    ll m = g[0].size();
    vector<ll> dx = {1, -1, 0, 0};
    vector<ll> dy = {0, 0, 1, -1};
    ll x = u.x;
    ll y = u.y;
    d[x][y] = 0;
    queue<cord> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (ll i = 0; i < 4; ++i) {
            ll xn = u.x +dx[i];
            ll yn = u.y +dy[i];
            if (!check(xn, yn, n, m)) continue;
            if (g[xn][yn] == '#' or d[xn][yn] < INF) continue;
            d[xn][yn] = d[u.x][u.y] + 1;
            q.push({xn, yn});
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >>m;
    grid g(n);
    for (ll i = 0; i < n; ++i) {
        cin >> g[i];
    }
    cord start;
    cin >> start.x >> start.y;
    --start.x; --start.y;
    vector<vector<ll>> d (n, vector<ll>(m, INF));
    bfs(g, start, d);
    for (const vector<ll> &row : d) {
        for (ll el : row)
            cout << (el == INF ? -1 : el) << ' ';
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define INF (1e18)

using namespace std;

using ll = long long;
using event = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<event> e;
    for (ll i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        e.emplace_back(l, 1);
        e.emplace_back(r+1, -1);
    }
    sort(e.begin(), e.end());
    event ans(-1,-1);
    ll cnt=0;
    for (auto elem : e) {
        cnt += elem.second;
        if (cnt > ans.second) {
            ans.first = elem.first;
            ans.second = cnt;
        }
    }
    cout << ans.second << ' ' << ans.first <<'\n';
    return 0;
}
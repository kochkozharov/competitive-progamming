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
    ll cnt=0;
    ll sum = 0;
    ll l = -1;
    for (event elem : e) {
        ll r = elem.first;
        cnt += elem.second;
        if (cnt > 0 and l == -1) {
            l = r;
        }
        if (cnt == 0) {
            sum += r-1 - l + 1;
            l = -1;
        }
    }
    cout << sum << '\n';
    return 0;
}
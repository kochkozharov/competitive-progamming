#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define INF (1e18)

using namespace std;

using ll = long long;
using seg= pair<ll, ll>;

bool cmp(const seg &a, const seg &b) {
    if(a.second != b.second) {
        return (a.second < b.second);
    }
    return a.first < b.first; 
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<seg> s;
    for (ll i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        s.emplace_back(l, r);
    }
    sort(s.begin(), s.end(), cmp);
    ll cnt = 1;
    ll last_pos = s[0].second;
    for (auto m : s) {
        if (m.first >= last_pos) {
            ++cnt;
            last_pos = m.second;
        }
    }
    cout << cnt <<'\n';
    return 0;
}
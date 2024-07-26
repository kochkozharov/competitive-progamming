#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define INF (1e18)

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> pr(n+1);
    for (auto i = 1; i < n+1; ++i) {
        ll l;
        cin >> l;
        pr[i] = pr[i-1] + l;
    }
    ll req;
    cin >> req;
    for (auto i = 0; i < req; ++i) {
        ll l,r;
        cin >> l >> r;
        --l;
        cout << pr[r] - pr[l] << '\n';
    }
    return 0;
}
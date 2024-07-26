#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

using ll= long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
    }
    ll count =0;
    sort(p.begin(), p.end());
    
    cout << count << '\n';
    return 0;
}
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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (ll i=1; i < n; ++i) {
        if (a[i]-a[i-1] != 1) {
            cout << "Scammed" << endl;
            return 0;
        }
    }
    cout << "Deck looks good" << endl;
    return 0;
}
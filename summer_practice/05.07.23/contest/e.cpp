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
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        sum += (a * (i + 1) * (n - i));
    }
    cout << sum << '\n';
    return 0;
}
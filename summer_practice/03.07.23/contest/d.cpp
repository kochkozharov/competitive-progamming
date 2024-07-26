#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

using ll= unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, a0;
    cin >> n >> a0;
    ll res = a0 % (1000000000 +7);
    ll mx1 = 0;
    ll mx2 = 0;
    for (ll i = 1; i <= n; ++i) {
        res = (res*5) % (1000000000 +7);
        if (res > mx1) {
            mx2 = mx1;
            mx1 = res;
        }
        else if (res > mx2) mx2 = res;
    }
    cout << mx2 << ' '<< mx1 << endl;
    return 0;
}

#include <iostream>
 
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    if (n == 0) {cout << 1 << '\n'; return 0;}
    ll f = 1;
    for (ll i = 1; i <= n; ++i) {
        f = f * i;
        f = f % (1000000000 +7);
    }
    cout << f << '\n';
    return 0;
}
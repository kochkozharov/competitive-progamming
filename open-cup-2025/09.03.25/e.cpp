#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    ll cnt_one_shot = 0;
    for (ll i = 0; i < n; ++i) {
        ll d;
        cin >> d;
        if (d >= l && d <= r) {
            cnt_one_shot++;
        }
    }
    if (cnt_one_shot > m) {
        cout << m;
        return 0;
    }
    ll rest = m - cnt_one_shot;
    ll res = rest / 2 + cnt_one_shot;
    if (res >= n) {
        cout << "lzdak!";
    }
    else {
        cout << res;
    }
}
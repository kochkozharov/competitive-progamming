#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1) {
        cout << "YES" << '\n' << n << '\n';
        for (int i = 0; i < n; ++i) {
            cout << 1 << ' ';
        }
        cout << '\n';
    }
    else if (k == 1) cout << "NO" << '\n';
    else if (k == 2) {
        if (n % 2 == 0) {
            cout << "YES" << '\n' << n / 2 << '\n';
            for (int i = 0; i < n; i+=2) {
                cout << 2 << ' ';
            }
        cout << '\n';
        }
        else cout << "NO" << '\n';
    }
    else {
        cout << "YES" << '\n' << n / 2 << '\n';
        if (n % 2 == 0) {
            for (int i = 0; i < n; i+=2) {
                cout << 2 << ' ';
            }
            cout << '\n';
        }
        else {
            for (int i = 0; i < n-3; i+=2) {
                cout << 2 << ' ';
            }
            cout << 3 << ' ';
            cout << '\n';
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

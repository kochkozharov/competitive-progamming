#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    int a[5];
    cin >> n;
    a[4] = n / 5000;
    n = n % 5000;
    a[3] = n / 1000;
    n = n % 1000;
    a[2] = n / 500;
    n = n % 500;
    a[1] = n / 200;
    n = n % 200;
    a[0] = n / 100;
    n = n % 100;
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
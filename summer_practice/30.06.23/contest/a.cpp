#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l, r;
    cin >> l >> r;
    while (l != 0 and r != 0) {
        reverse(a.begin()+l-1, a.begin()+r);
        cin >> l >> r;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}

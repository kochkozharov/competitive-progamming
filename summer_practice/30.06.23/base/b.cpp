#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l, r;
    do {
        cin >> l >> r;
        reverse(a+l-1, a+r-1);
    } while (l != 0 and r != 0);
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    delete[] a;
    return 0;
}

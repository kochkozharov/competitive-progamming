#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    long long sum = 0;
    while(n--) {
        long long a;
        cin >> a;
        sum += a;
    }
    cout << sum << '\n';
    return 0;
}

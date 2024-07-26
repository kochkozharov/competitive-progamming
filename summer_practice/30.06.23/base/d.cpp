#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string s, p;
    cin >> s >> p;
    int sum = 0;
    for (int i = 0; i < n - m + 1; ++i) {
        string sub = s.substr(i, m);
        if (sub == p) {
            ++sum;
        }
    }
    cout << sum << '\n';
}

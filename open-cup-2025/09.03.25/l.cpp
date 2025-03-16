#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
    ll n;
    ll s;
    std::cin >> n;
    std::vector<std::vector<ll> > numbers(n, std::vector<ll>(n));

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            std::cin >> numbers[i][j];  
        }
    }

    ll temp = -1;

    for (ll i = 0, j = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            for (ll k = 1; k < n - j; k++) {
                if (i + k < n && j + k < n) {
                    ll first = numbers[i][j];
                    ll last = numbers[i + k][j + k];
                    ll second = numbers[i][j + k];
                    ll third = numbers[i + k][j];

                    int arr[4];

                    arr[0] = first;
                    arr[1] = second;
                    arr[2] = third;
                    arr[3] = last;
                    
                    std::sort(std::begin(arr), std::end(arr));
                    if (arr[0] == arr[1] && arr[0] == arr[2] && arr[3] - arr[0]) {
                        if (arr[0] > temp) {
                            temp = arr[0];
                        }
                    }
                }
            }
        }
    }

    std::cout << temp;

    return 0;
}
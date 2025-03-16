#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        cin >> *(arr+i);
    }
    sort(begin(arr), end(arr));
    do {
        if (arr[0] == arr[1] + arr[2] + arr[3] && arr[4] == arr[1] * 3 + arr[2]) {
            for (int i : arr) {
                cout << i << ' ';
            }
            return 0;
        }
    } while(next_permutation(begin(arr), end(arr)));
}
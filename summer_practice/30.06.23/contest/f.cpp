#include <bits/stdc++.h>

using namespace std;

void solve() {
    int *arr; 
    int size; 
    cin >> size;
    arr = new int[size]; 
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int c =0;
    int temp; 
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                ++c;
            }
        }
    }
    cout << c << '\n';
    delete [] arr;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
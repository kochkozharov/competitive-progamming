#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;


    int prev = a;

    int cur = b;
    int cnt = 0;
    do {
        int tmp = cur;
        cur = (prev + cur)%10;
        cnt++;
        prev = tmp;
    } while (a != prev || b != cur);

    cout << cnt + 2;
}
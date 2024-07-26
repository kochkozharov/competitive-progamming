#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
    
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> min_heap;
    priority_queue<ll, vector<ll>, less<ll>> max_heap;
    min_heap.push(LLONG_MAX);
    max_heap.push(LLONG_MIN);
    ll c = 1;
    while(n--) {
        ll num;
        cin >> num;
        if (num >= min_heap.top()) min_heap.push(num);
        else max_heap.push(num);

        if (max_heap.size() > min_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (max_heap.size() + 1 < min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if (c%2) cout << min_heap.top() << '\n';
        else cout << max_heap.top() << '\n';
        ++c;
    }
    return 0;
}
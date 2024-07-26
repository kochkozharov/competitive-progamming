#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct rec {
   int x1, y1, x2, y2;
};

int intersection_square(rec &a, rec &b) {
    int x1 = min(a.x1, a.x2);
    int x2 = max(a.x1, a.x2);
    int x3 = min(b.x1, b.x2);
    int x4 = max(b.x1, b.x2);
    int y1 = min(a.y1, a.y2);
    int y2 = max(a.y1, a.y2);
    int y3 = min(b.y1, b.y2);
    int y4 = max(b.y1, b.y2);
    int l = max(x1, x3);
    int top = min(y2, y4);
    int r = min(x2, x4);
    int bottom = max(y1, y3);
    int width = r - l;
    int height = top - bottom;
    if (width < 0 || height < 0)
        return 0;
    return width*height;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    rec a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    int sa = abs(a.x2 - a.x1) * (abs(a.y2 - a.y1));
    int sb = abs(b.x2 - b.x1) * (abs(b.y2 - b.y1));
    cout << sa + sb - intersection_square(a, b);
}

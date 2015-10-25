#include <iostream>
#include <algorithm>

using namespace std;

struct Rect {
    int xl, yl;
    int xh, yh;
    int s;
} rect[101];

int ans;

void cal(int xl, int yl, int xh, int yh, int lo, int hi);

bool cmpx(const Rect &a, const Rect &b) {
    return a.xh < b.xh;
}

bool cutx(int xl, int yl, int xh, int yh, int lo, int hi) {
    sort(rect+lo, rect+hi+1, cmpx);
    int x, s = 0;
    for (int i = lo; i < hi; i++) {
        s += rect[i].s;
        x = rect[i].xh;
        if (s == (x - xl) * (yh - yl)) {
            cal(xl, yl, x, yh, lo, i);
            cal(x, yl, xh, yh, i + 1, hi);
            return true;
        }
    }
    return false;
}

bool cmpy(const Rect &a, const Rect &b) {
    return a.yh < b.yh;
}

bool cuty(int xl, int yl, int xh, int yh, int lo, int hi) {
    sort(rect+lo, rect+hi+1, cmpy);
    int y, s = 0;
    for (int i = lo; i < hi; i++) {
        s += rect[i].s;
        y = rect[i].yh;
        if (s == (xh - xl) * (y - yl)) {
            cal(xl, yl, xh, y, lo, i);
            cal(xl, y, xh, yh, i + 1, hi);
            return true;
        }
    }
    return false;
}

void cal(int xl, int yl, int xh, int yh, int lo, int hi) {
    int s = (xh - xl) * (yh - yl);
    if (s <= ans) return;
    if (cutx(xl, yl, xh, yh, lo, hi)) return;
    if (cuty(xl, yl, xh, yh, lo, hi)) return;
    if (s > ans) ans = s;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        ans = 0;
        int x, y, n;
        cin >> x >> y >> n;
        for (int i = 0; i < n; i++) {
            cin >> rect[i].xl >> rect[i].yl
                >> rect[i].xh >> rect[i].yh;
            rect[i].s = (rect[i].xh - rect[i].xl) * (rect[i].yh - rect[i].yl);
        }
        cal(0, 0, x, y, 0, n-1);
        cout << ans << endl;
    }
}
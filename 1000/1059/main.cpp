#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define EPS 1E-6
#define INF 1E+15

int main() {
    int N;
    cin >> N;
    while (N--) {
        double x1, x2, x3, y1, y2, y3;

        cin >> x1 >> y1
        >> x2 >> y2
        >> x3 >> y3;

        double s1, s2, x0, y0;

        if (fabs(y2 - y3) < EPS) s1 = INF;
        else s1 = (x3 - x2) / (y2 - y3);

        if (fabs(y1 - y3) < EPS) s2 = INF;
        else s2 = (x3 - x1) / (y1 - y3);

        if (s1 == INF) {
            x0 = x1;
            y0 = x0 * s2 - x2 * s2 + y2;
        } else if (s2 == INF) {
            x0 = x2;
            y0 = x0 * s1 - x1 * s1 + y1;
        } else {
            x0 = (x1 * s1 - x2 * s2 - y1 + y2) / (s1 - s2);
            y0 = x0 * s1 - x1 * s1 + y1;
        }

        // 重要!! 得修正x0和y0!!!!!
        x0 = fabs(x0) < EPS ? 0 : x0;
        y0 = fabs(y0) < EPS ? 0 : y0;

        cout << fixed << setprecision(4) << x0 << ' '
        << fixed << setprecision(4) << y0 << endl;
    }
}
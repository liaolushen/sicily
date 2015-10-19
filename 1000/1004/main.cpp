#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define EPS 1E-6
#define INF 1E+15

bool equal(double a, double b) {
    return fabs(a - b) < EPS;
}

struct Line {
    double x1, y1, x2, y2;
    double k, b;
    bool operator<(const Line& other) const {
        if (equal(k, other.k)) {
            if (k == INF) {
                if (equal(b, other.b)) {
                    if (y1 == other.y1) return y2 < other.y2;
                    else return y1 < other.y1;
                } else {
                    return b < other.b;
                }
            } else if (equal(b, other.b)) {
                if (x1 == other.x1) return x2 < other.x2;
                else return x1 < other.x1;
            } else {
                return b < other.b;
            }
        } else {
            return k < other.k;
        }
    }
} lines[10001];

int main() {
    int N;
    while (cin >> N && N != 0) {
        double x1, y1, x2, y2;
        for (int i = 0; i < N; i++) {
            cin >> x1 >> y1 >> x2 >> y2;

            if (x1 == x2) {
                lines[i].k = INF;
                lines[i].b = x1;
            } else {
                lines[i].k = (y1 - y2) / (x1 - x2);
                lines[i].b = y1 - lines[i].k * x1;
            }

            if (lines[i].k == INF && y1 > y2) {
                swap(y1, y2);
            } else if (x1 > x2) {
                swap(x1, x2);
                swap(y1, y2);
            }
            lines[i].x1 = x1; lines[i].y1 = y1;
            lines[i].x2 = x2; lines[i].y2 = y2;
        }
        sort(lines, lines + N);

        int index = 1;
        for (int i = 1; i < N; i++) {
            if (equal(lines[i].k, lines[i-1].k) && equal(lines[i].b, lines[i-1].b)) {
                if (lines[i].k == INF && (lines[i-1].y2 >= lines[i].y1)) {
                    lines[i].y1 = lines[i-1].y1;
                    lines[i].y2 = lines[i].y2 > lines[i-1].y2 ? lines[i].y2 : lines[i-1].y2;
                    continue;
                } else if (lines[i].k != INF && lines[i-1].x2 >= lines[i].x1) {
                    lines[i].x1 = lines[i-1].x1;
                    lines[i].x2 = lines[i].x2 > lines[i-1].x2 ? lines[i].x2 : lines[i-1].x2;
                    continue;
                }
            }
            index++;
        }
        cout << index << endl;
    }
}
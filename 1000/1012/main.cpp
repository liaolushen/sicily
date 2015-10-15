#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

#define RADIUS 1.0

int main() {
    int n;
    while (cin >> n && n != 0) {
        double x , y;
        vector<double> cylinders(n);
        for (int i = 0; i < n; i++) cin >> cylinders[i];
        sort(cylinders.begin(), cylinders.end());
        x = cylinders[0];
        y = RADIUS;
        for (int i = 1; i < n; i++) {
            double preX = x;
            x = (cylinders[0] + cylinders[i])/2;
            y += sqrt(pow(2 * RADIUS, 2.0) - pow(x - preX, 2.0));
        }
        cout << fixed << setprecision(4)
        << x << ' ' << fixed << setprecision(4) << y << endl;
    }
}